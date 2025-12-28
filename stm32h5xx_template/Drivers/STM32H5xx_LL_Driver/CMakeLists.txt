cmake_minimum_required(VERSION 3.22)
enable_language(C ASM)

# LL库头文件
set(STM32_LL_Inc
  ${CMAKE_CURRENT_SOURCE_DIR}/Inc
  ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS
  ${CMAKE_CURRENT_SOURCE_DIR}/../CMSIS/Device
  ${CMAKE_SOURCE_DIR}/Core/Inc
)
# LL库源文件
file(GLOB STM32_LL_Src ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)

# LL库接口 = LL库头文件 + 符号定义 (STM32_Configs)
add_library(STM32_Drivers_Interface INTERFACE)
target_include_directories(STM32_Drivers_Interface INTERFACE ${STM32_LL_Inc})
target_compile_definitions(STM32_Drivers_Interface INTERFACE ${STM32_Configs})

# 创建LL库
add_library(STM32_Drivers OBJECT)
target_sources(STM32_Drivers PRIVATE ${STM32_LL_Src})
target_link_libraries(STM32_Drivers PRIVATE STM32_Drivers_Interface)

# 将LL库添加至项目中
target_link_libraries(${CMAKE_PROJECT_NAME} STM32_Drivers)