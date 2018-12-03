project(FmCppDeviceSim)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenSSL REQUIRED)

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

# set FM SDK directory
set(_FM_SDK_DIR ${PROJECT_SOURCE_DIR}/../../../cpp)
add_subdirectory(${_FM_SDK_DIR} ${_FM_SDK_DIR}/lib)

include_directories(${_FM_SDK_DIR}/include)
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
target_link_libraries(FmCppDeviceSim
    fm_sdk
    ${Boost_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    gRPC::grpc++
    protobuf::libprotobuf
    )
