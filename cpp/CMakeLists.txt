cmake_minimum_required(VERSION 2.8)

project(FmSdk)

add_compile_options(-std=c++11)

include_directories(include)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/source/IClient.cpp
    ${PROJECT_SOURCE_DIR}/source/Device.cpp
    ${PROJECT_SOURCE_DIR}/source/Pilot.cpp
    ${PROJECT_SOURCE_DIR}/source/core/CoreClient.cpp
    ${PROJECT_SOURCE_DIR}/source/core/https/IHttpsClient.cpp
    ${PROJECT_SOURCE_DIR}/source/event/input/UserEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/event/output/FacadeEvent.cpp
    ${PROJECT_SOURCE_DIR}/source/state/IState.cpp
    ${PROJECT_SOURCE_DIR}/source/state/device/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/state/pilot/Disconnected.cpp
    ${PROJECT_SOURCE_DIR}/source/timer/ITimer.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/Channel.cpp
    ${PROJECT_SOURCE_DIR}/source/traffic/socket/ISocket.cpp)

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/IClient.hpp
    ${PROJECT_SOURCE_DIR}/include/Device.hpp
    ${PROJECT_SOURCE_DIR}/include/Pilot.hpp
    ${PROJECT_SOURCE_DIR}/include/core/CoreClient.hpp
    ${PROJECT_SOURCE_DIR}/include/core/https/IHttpsClient.hpp
    ${PROJECT_SOURCE_DIR}/include/event/input/UserEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/event/output/FacadeEvent.hpp
    ${PROJECT_SOURCE_DIR}/include/state/IState.hpp
    ${PROJECT_SOURCE_DIR}/include/state/device/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/state/pilot/Disconnected.hpp
    ${PROJECT_SOURCE_DIR}/include/timer/ITimer.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/Channel.hpp
    ${PROJECT_SOURCE_DIR}/include/traffic/socket/ISocket.hpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_library(fm_sdk STATIC ${SOURCES} ${HEADERS})
