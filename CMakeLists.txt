cmake_minimum_required(VERSION 3.16)
project(zero-to-main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(DEVICE_FLAGS NRF51=1 NRF51822=1)
set(DEVICE_C_FLAGS -mcpu=cortex-m0 -mthumb -mabi=aapcs -mfloat-abi=soft -march=armv6-m -ffunction-sections -fdata-sections -fno-strict-aliasing)
set(DEVICE_LD_FLAGS -Wl,--gc-sections -lnosys --specs=nano.specs)

include(cmake/nrf-sdk.cmake)

add_executable(minimal src/bin/minimal.c src/startup_nrf51.c)
target_compile_definitions(minimal PRIVATE "${DEVICE_FLAGS}")
target_compile_options(minimal PRIVATE "${DEVICE_C_FLAGS}")
target_link_options(minimal PRIVATE -T${CMAKE_CURRENT_LIST_DIR}/nrf51822.x ${DEVICE_LD_FLAGS})
target_link_libraries(minimal PRIVATE nrf-sdk)