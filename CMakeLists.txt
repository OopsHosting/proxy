cmake_minimum_required(VERSION 3.8)
PROJECT(proxy)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS        OFF) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
find_package(Boost 1.65.0 REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS})

if(Boost_FOUND)
    set(SOURCES main.cpp src/tcp/tcp_proxy.cpp src/udp/udp_proxy.cpp src/tcp.cpp src/udp.cpp)

    set(HEADERS src/tcp/tcp_proxy.h src/udp/udp_proxy.h src/tcp.h src/udp.h)

    add_executable(proxy ${SOURCES} ${HEADERS})

    include_directories(src src/tcp src/udp)

    target_link_libraries(proxy ${Boost_LIBRARIES})
endif()