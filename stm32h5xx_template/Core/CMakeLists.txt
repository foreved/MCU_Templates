cmake_minimum_required(VERSION 3.22)
enable_language(C ASM)

# 核心头文件
set(Core_Inc
  ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)
# 核心源文件
file(GLOB Core_Src ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)
# 启动文件
list(APPEND Core_Src ${Startup_Path})

# 创建核心库
add_library(Core OBJECT)
target_include_directories(Core PRIVATE ${Core_Inc})
target_sources(Core PRIVATE ${Core_Src})
target_link_libraries(Core PRIVATE STM32_Drivers_Interface)

# 将核心库添加至项目中
target_link_libraries(${CMAKE_PROJECT_NAME} Core)