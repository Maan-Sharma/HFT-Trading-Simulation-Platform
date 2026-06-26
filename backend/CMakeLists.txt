cmake_minimum_required(VERSION 3.22)

project(
    HFTTradingSimulation
    VERSION 1.0
    LANGUAGES CXX
)

# =====================
# Compiler Settings
# =====================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# =====================
# Performance Flags
# =====================

if(MSVC)

    add_compile_options(
        /W4
        /O2
        /permissive-
    )

else()

    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -O3
        -march=native
    )

endif()

# =====================
# Source Files
# =====================

file(
    GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

# =====================
# Exchange Executable
# =====================

add_executable(
    exchange
    apps/exchange/main.cpp
    ${SOURCES}
)

target_include_directories(
    exchange
    PRIVATE
    include
)
file(
    GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)
find_package(Boost REQUIRED)

find_package(Threads REQUIRED)

target_link_libraries(
    exchange
    PRIVATE
    ws2_32
    mswsock
    Threads::Threads
)
find_package(Boost REQUIRED COMPONENTS system json)

target_link_libraries(
    exchange
    PRIVATE
    Boost::system
    Boost::json
)