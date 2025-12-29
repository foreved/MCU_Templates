#include "main.h"

static void CACHE_Enable(void);
static void SystemClock_Config(void);

int main(void)
{
    CACHE_Enable();
    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
    SystemClock_Config();

    

    while (1)
    {
    }
}

/**
 * @brief  配置 STM32 的电压等级, 读取操作等待周期, 时钟树. 这三者需要参考手册, 确定合适的值.
 * @param  无
 * @retval 无
 */
static void SystemClock_Config(void)
{
    // 以下内容相互联系, 需查手册确定合适的值
    // 1) VCORE 域电压等级; 2) Flash 等待周期; 3) AHB 频率

    /************************ VCORE 域电压等级 ************************/
    // 配置 VCORE 域电压等级, 等级越小, 电压越高, 频率越高
    LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE0);
    while (LL_PWR_IsActiveFlag_VOS() == 0)
    {
    }
    /************************ VCORE 域电压等级 ************************/

    /************************ Flash 等待周期 ************************/
    // 配置读取 Flash 的等待周期
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);
    /************************ Flash 等待周期 ************************/
    
    /************************ RCC 时钟树 ************************/
    // 使能 HSE
    LL_RCC_HSE_Enable();
    while (LL_RCC_HSE_IsReady() != 1)
    {
    }

    // 选择 PLL1 的时钟源为 HSE
    LL_RCC_PLL1_SetSource(LL_RCC_PLL1SOURCE_HSE);
    // 配置 PLL1 的分频系数和倍频系数
    LL_RCC_PLL1P_Enable();
    LL_RCC_PLL1Q_Enable();
    LL_RCC_PLL1R_Enable();
    LL_RCC_PLL1FRACN_Disable(); // 倍频系数 N, 不使用小数, 即 N 为整型
    LL_RCC_PLL1_SetVCOInputRange(LL_RCC_PLLINPUTRANGE_2_4);
    LL_RCC_PLL1_SetVCOOutputRange(LL_RCC_PLLVCORANGE_WIDE);
    // 分频系数 M
    LL_RCC_PLL1_SetM(4);
    // 倍频系数 N
    LL_RCC_PLL1_SetN(250);
    // 三个输出通道各自的分频系数
    LL_RCC_PLL1_SetP(2);
    LL_RCC_PLL1_SetQ(2);
    LL_RCC_PLL1_SetR(2);
    // 使能 PLL1
    LL_RCC_PLL1_Enable();
    while (LL_RCC_PLL1_IsReady() != 1)
    {
    }

    // 设置 AHB, APB1, APB2, APB3 的分频系数
    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
    LL_RCC_SetAPB3Prescaler(LL_RCC_APB3_DIV_1);

    // 选择 PLL1 作为系统时钟源
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL1);
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL1)
    {
    }

    // 更新 SystemCoreClock
    SystemCoreClockUpdate();
    /************************ RCC 时钟树 ************************/
    
    // 配置 SysTick 周期为 1ms; 使能 SysTick, 但未开启中断请求
    LL_Init1msTick(SystemCoreClock);
}

/**
 * @brief  Enable ICACHE with 2-ways set-associative configuration.
 * @param  None
 * @retval None
 */
static void CACHE_Enable(void)
{
    /* Enable instruction cache (default 2-ways set associative cache) */
    LL_ICACHE_Enable();
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif