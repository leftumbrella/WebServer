cmake_minimum_required(VERSION 3.31.4)
set(WS_PROJECT_NAME WebServer)
set(CMAKE_CXX_STANDARD 20)
project(${WS_PROJECT_NAME})

# boost
find_package(Boost REQUIRED COMPONENTS json system thread asio property_tree redis)
find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

# 指定可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(${WS_PROJECT_NAME} main.cpp
    RequestHandler.cpp
    RequestHandler.h
    easycode/iniReader.h
    Utils.h
    include/RedisApi.h
    database/Redis.cpp
    database/Redis.h
)
find_package(OpenMP)
target_link_libraries(${WS_PROJECT_NAME}
    PRIVATE
        Boost::system
        Boost::thread
        Boost::json
        OpenSSL::SSL
        OpenSSL::Crypto
        opencv_core
        opencv_imgproc
        opencv_highgui
)