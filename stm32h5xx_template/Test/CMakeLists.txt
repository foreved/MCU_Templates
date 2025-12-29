cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)

# 测试头文件
set(Test_Inc
  ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)
# 测试源文件
file(GLOB Test_Src ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)

# 测试用户库
add_library(Test OBJECT)
target_include_directories(Test PRIVATE ${Test_Inc})
target_sources(Test PRIVATE ${Test_Src})
target_link_libraries(Test PRIVATE STM32_Drivers_Interface)
target_include_directories(STM32_Drivers_Interface INTERFACE ${Test_Inc})

# 将测试库添加至项目中
target_link_libraries(${CMAKE_PROJECT_NAME} Test)