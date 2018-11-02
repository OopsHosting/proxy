cmake_minimum_required(VERSION 3.8)
PROJECT(proxy)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS        OFF) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost 1.65.0 COMPONENTS system log log_setup thread date_time filesystem regex chrono atomic REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

if(Boost_FOUND)
    add_executable(proxy src/proxy.cpp)
    target_link_libraries(proxy ${Boost_LIBRARIES})
endif()