project(FmCppDeviceSim)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(${PROJECT_SOURCE_DIR}/../../../cpp ${PROJECT_SOURCE_DIR}/../../../cpp/lib)

include_directories(${PROJECT_SOURCE_DIR}/../../../cpp/include)
include_directories(${PROJECT_SOURCE_DIR}/example)

set(FILES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/example/AsioHttpsClient.cpp
    ${PROJECT_SOURCE_DIR}/example/AsioHttpsClient.hpp
    ${PROJECT_SOURCE_DIR}/example/AsioListener.cpp
    ${PROJECT_SOURCE_DIR}/example/AsioListener.hpp
    ${PROJECT_SOURCE_DIR}/example/AsioTcpClient.cpp
    ${PROJECT_SOURCE_DIR}/example/AsioTcpClient.hpp
    ${PROJECT_SOURCE_DIR}/example/AsioUdpClient.cpp
    ${PROJECT_SOURCE_DIR}/example/AsioUdpClient.hpp
    ${PROJECT_SOURCE_DIR}/example/Timer.cpp
    ${PROJECT_SOURCE_DIR}/example/Timer.hpp
    ${PROJECT_SOURCE_DIR}/example/TimerThread.cpp
    ${PROJECT_SOURCE_DIR}/example/TimerThread.hpp
    )

add_executable(FmCppDeviceSim ${FILES})
target_link_libraries(FmCppDeviceSim fm_sdk libprotobuf grpc++)
