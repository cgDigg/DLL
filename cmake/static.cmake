# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.20)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("dll")
enable_language(ASM_MASM)
add_library(function STATIC src/function.c)
target_link_libraries(function PRIVATE user32)
target_link_libraries(function PRIVATE shell32)
add_library(cmd STATIC src/cmd.c)
add_library(random STATIC src/random.c)
add_library(python_function STATIC src/python_function.c)
target_link_libraries(python_function PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/python313.lib")
add_library(value STATIC src/value.c)
target_include_directories(value PRIVATE header)
add_library(int_str STATIC src/int_str.cpp)
add_library(maths STATIC src/maths.c)
set_target_properties(maths PROPERTIES C_STANDARD 11)
add_library(python STATIC src/python.c)
target_link_libraries(python PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/python313.lib")
target_include_directories(python PRIVATE header/include)
add_library(times STATIC src/time.c)
add_library(cpuid STATIC "${CMAKE_CURRENT_SOURCE_DIR}/cpu.asm")