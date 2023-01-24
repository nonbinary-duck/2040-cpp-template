cmake_minimum_required(VERSION 3.13)

set(PICO_SDK_PATH ../../lib/pico-sdk) # Define a path to the sdk (from the build dir)
set(PICO_BOARD pico_w) # Set our board to pico_w

include(pico_sdk_import.cmake) # Import the pico toolchain

project(<PROJECT_NAME> C CXX ASM) # Define the project

set(CMAKE_C STANDARD 11)
set(CMAKE_CXX_STANDARD 23) # Use CPP 23

pico_sdk_init() # Let the sdk do its thing

# Include our headers etc
include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

add_executable(<PROJECT_NAME> main.cpp)

# No idea what this is doing, copied it from https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk
pico_enable_stdio_usb(pico 1)
pico_enable_stdio_uart(pico 0)
pico_add_extra_outputs(pico)

# Again, no idea what this is doing
target_include_directories(<PROJECT_NAME> PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_link_libraries(<PROJECT_NAME> pico_cyw43_arch_lwip_threadsafe_background pico_stdlib)
