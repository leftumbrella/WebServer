cmake_minimum_required(VERSION 3.30)
set(WS_PROJECT_NAME WebServer)
set(CMAKE_CXX_STANDARD 20)
project(${WS_PROJECT_NAME})

# 指定可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${WS_PROJECT_NAME} main.cpp)
