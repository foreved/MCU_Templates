/**
  ******************************************************************************
  * @file    Templates_LL/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MAIN_H
#define MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_ll_adc.h"
#include "stm32h5xx_ll_bus.h"
#include "stm32h5xx_ll_comp.h"
#include "stm32h5xx_ll_cortex.h"
#include "stm32h5xx_ll_crc.h"
#include "stm32h5xx_ll_crs.h"
#include "stm32h5xx_ll_dac.h"
#include "stm32h5xx_ll_dcache.h"
#include "stm32h5xx_ll_dma.h"
#include "stm32h5xx_ll_exti.h"
#include "stm32h5xx_ll_fmac.h"
#include "stm32h5xx_ll_gpio.h"
#include "stm32h5xx_ll_i2c.h"
#include "stm32h5xx_ll_i3c.h"
#include "stm32h5xx_ll_icache.h"
#include "stm32h5xx_ll_iwdg.h"
#include "stm32h5xx_ll_lptim.h"
#include "stm32h5xx_ll_lpuart.h"
#include "stm32h5xx_ll_opamp.h"
#include "stm32h5xx_ll_pwr.h"
#include "stm32h5xx_ll_rcc.h"
#include "stm32h5xx_ll_rng.h"
#include "stm32h5xx_ll_rtc.h"
#include "stm32h5xx_ll_spi.h"
#include "stm32h5xx_ll_system.h"
#include "stm32h5xx_ll_tim.h"
#include "stm32h5xx_ll_usart.h"
#include "stm32h5xx_ll_utils.h"
#include "stm32h5xx_ll_wwdg.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/***************************** 优先级分组 *****************************/
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 8 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 7 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 6 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 5 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 4 bit  for subpriority */
#define NVIC_PRIORITYGROUP_5         ((uint32_t)0x00000002) /*!< 5 bits for pre-emption priority,
                                                                 3 bit  for subpriority */
#define NVIC_PRIORITYGROUP_6         ((uint32_t)0x00000001) /*!< 6 bits for pre-emption priority,
                                                                 2 bit  for subpriority */
#define NVIC_PRIORITYGROUP_7         ((uint32_t)0x00000000) /*!< 7 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
/***************************** 优先级分组 *****************************/

#endif /* MAIN_H */
