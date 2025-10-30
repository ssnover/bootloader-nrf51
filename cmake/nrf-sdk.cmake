if(NOT TARGET nrf-sdk)

set(NRF_SDK_DIR "$ENV{HOME}/Downloads/nRF5_SDK_12.3.0_d7731ad")

add_library(nrf-sdk INTERFACE)
target_compile_definitions(nrf-sdk INTERFACE ${DEVICE_FLAGS})
target_include_directories(
    nrf-sdk 
    INTERFACE 
        "${NRF_SDK_DIR}/components/toolchain"
        "${NRF_SDK_DIR}/components/toolchain/cmsis/include"
        "${NRF_SDK_DIR}/components/device"
)

endif()