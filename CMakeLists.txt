# 指定CMake的最小版本
cmake_minimum_required(VERSION 3.22)

# 指定C、C++标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# 指定编译类型
set(CMAKE_BUILD_TYPE Release)

# 根据构建类型定义宏
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(NDEBUG)
    message(STATUS "Building in Release mode, defining NDEBUG macro")
else()
    add_compile_definitions(DEBUG)
    message(STATUS "Building in Debug mode, defining DEBUG macro")
endif()

# 生成complie_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 设置静态库文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
# 动态库文件目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
# 可执行文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)

# 指定项目名称
project(project-name VERSION 1.0)

# 开启test选项
enable_testing()

# 添加Option选项
option(Enable_Andorid "Enable Android build option" ON)

if(Enable_Android)
    message(STATUS "Enable Android build option")
    set(CMAKE_SYSTEM_NAME ANDROID)
    set(CMAKE_ANDROID_NDK $ENV{NDK_HOME})
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_ANDROID_NDK}/build/cmake/android.toolchain.cmake)
    set(ANDROID_PLATFORM android-33)
    set(ANDROID_ABI arm64-v8a)
endif()

# 添加子工程
# add_subdirectory(src)
# add_subdirectory(example)
# add_subdirectory(test)
add_subdirectory(benchmark)
