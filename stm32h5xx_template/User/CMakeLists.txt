cmake_minimum_required(VERSION 3.22)
enable_language(C ASM)

# 用户头文件
set(User_Inc
  ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)
# 用户源文件
file(GLOB User_Src ${CMAKE_CURRENT_SOURCE_DIR}/Src/*.c)

# 创建用户库
add_library(User OBJECT)
target_include_directories(User PRIVATE ${User_Inc})
target_sources(User PRIVATE ${User_Src})
target_link_libraries(User PRIVATE STM32_Drivers_Interface)
target_include_directories(STM32_Drivers_Interface INTERFACE ${User_Inc})

# 将核心库添加至项目中
target_link_libraries(${CMAKE_PROJECT_NAME} User)