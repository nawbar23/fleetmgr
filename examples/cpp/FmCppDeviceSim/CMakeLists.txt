project(FmCppDeviceSim)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

find_package(Boost REQUIRED COMPONENTS system)

# set FM SDK directory
set(_FM_SDK_DIR ${PROJECT_SOURCE_DIR}/../../../cpp)
add_subdirectory(${_FM_SDK_DIR} ${_FM_SDK_DIR}/lib)

include_directories(${_FM_SDK_DIR}/include)
include_directories(${_FM_SDK_DIR}/generated)
include_directories(${PROJECT_SOURCE_DIR}/example)

set(FILES
    ${PROJECT_SOURCE_DIR}/ISimulator.cpp
    ${PROJECT_SOURCE_DIR}/ISimulator.hpp
    ${PROJECT_SOURCE_DIR}/DeviceSimulator.cpp
    ${PROJECT_SOURCE_DIR}/DeviceSimulator.hpp
    ${PROJECT_SOURCE_DIR}/PilotSimulator.cpp
    ${PROJECT_SOURCE_DIR}/PilotSimulator.hpp
    ${PROJECT_SOURCE_DIR}/example/BoostHttpsClient.cpp
    ${PROJECT_SOURCE_DIR}/example/BoostHttpsClient.hpp
    ${PROJECT_SOURCE_DIR}/example/BoostListener.cpp
    ${PROJECT_SOURCE_DIR}/example/BoostListener.hpp
    ${PROJECT_SOURCE_DIR}/example/BoostTcpSocket.cpp
    ${PROJECT_SOURCE_DIR}/example/BoostTcpSocket.hpp
    ${PROJECT_SOURCE_DIR}/example/BoostUdpSocket.cpp
    ${PROJECT_SOURCE_DIR}/example/BoostUdpSocket.hpp
    ${PROJECT_SOURCE_DIR}/example/Timer.cpp
    ${PROJECT_SOURCE_DIR}/example/Timer.hpp
    ${PROJECT_SOURCE_DIR}/example/TimerThread.cpp
    ${PROJECT_SOURCE_DIR}/example/TimerThread.hpp
    )

if(${CMAKE_GENERATOR} MATCHES "Unix Makefiles")
    message(STATUS ${CMAKE_BUILD_TOOL})
    set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j4")
    message(STATUS "Added arguments to CMAKE_BUILD_TOOL: ${CMAKE_MAKE_PROGRAM}")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    message(STATUS "Added parallel build arguments to CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()

add_library(_fm_example STATIC ${FILES})
target_link_libraries(_fm_example
    fm_sdk
    )

foreach (_target deviceSim pilotSim)

    add_executable(${_target} "${_target}.cpp")
    target_link_libraries(${_target}
        ${Boost_LIBRARIES}
        _fm_example
        )

endforeach()
