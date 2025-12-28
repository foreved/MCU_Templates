cmake_minimum_required(VERSION 3.22)

# 编译器设置
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# 编译类型
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

############### 配置 (需修改) ###############
# 修改项目名称
set(CMAKE_PROJECT_NAME task)
# 设置启动文件
set(Startup_Path ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/Startup/startup_stm32h503xx.s)
# 设置链接脚本
set(Link_Script_Path ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/Linker/STM32H503xx_FLASH.ld)
# 修改宏定义, 包括 mcu 型号, HSE 频率, HSI 频率
set(STM32_Configs
    USE_FULL_LL_DRIVER
	STM32H503xx
	CSI_VALUE=4000000
	HSI_VALUE=64000000 
	HSE_VALUE=8000000
)

############### 配置 ###############

# 创建项目
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})
add_executable(${CMAKE_PROJECT_NAME})
enable_language(C ASM)

# 指定链接脚本
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T \"${Link_Script_Path}\"")
# 链接数学库
target_link_libraries(${CMAKE_PROJECT_NAME} m)

################### 构建项目 ###################
# 1. 构建 MCU 驱动
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32H5xx_ll_Driver)

# 2. 构建其它驱动库
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Drivers/xxx_Driver)
# ... 若干驱动

# 3. 构建用户库
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/User)

# 4. 构建主程序
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Core)
################### 构建项目 ###################
