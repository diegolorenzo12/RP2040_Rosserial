cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(RP2040_Rosserial C CXX ASM)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_PATH ${PROJECT_SOURCE_DIR})

pico_sdk_init()

include_directories(include libs libs/rosserial)

add_executable(main 
    src/main.cpp
    libs/rosserial/time.cpp
    libs/rosserial/duration.cpp
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

pico_add_extra_outputs(main)

target_link_libraries(main pico_stdlib)