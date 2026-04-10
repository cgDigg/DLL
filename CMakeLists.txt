# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
if(0)
project("dll" C )
enable_language(ASM_MASM)
add_library(function SHARED src/function.c)
target_link_libraries(function PRIVATE user32)
target_link_libraries(function PRIVATE shell32)
add_library(cmd SHARED src/cmd.c)
add_library(random SHARED src/random.c)
add_library(python_function SHARED src/python_function.c)
target_link_libraries(python_function PRIVATE lib/python313)#can use other python lib
add_library(value SHARED src/value.c)
target_include_directories(value PRIVATE header)
add_library(int_str SHARED src/int_str.cpp)
add_library(maths SHARED src/maths.c)
add_library(python SHARED src/python.c)
target_link_libraries(python PRIVATE lib/python313)#can use other python lib
target_include_directories(python PRIVATE header/include)
add_library(times SHARED src/time.c)
add_library(cpuid SHARED src/cpu.asm)
target_link_options(cpuid_dll PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/def/cpuid.def")
else()

include("cmake/static.cmake")
endif()