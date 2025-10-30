#include <nrf51.h>

extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sstack;
extern uint32_t _estack;

int main();
void Reset_Handler();
void NMI_Handler();
void HardFault_Handler();

typedef struct _DeviceVectors {
    void* pvStack;
    void* pfnReset_Handler;
    void* pfnNMI_Handler;
    void* pfnHardFault_Handler;
} DeviceVectors;

__attribute__((section(".vectors"))) const DeviceVectors exception_table = {
    .pvStack = (void*)(&_estack),
    .pfnReset_Handler = (void*)Reset_Handler,
    .pfnNMI_Handler = (void*)NMI_Handler,
    .pfnHardFault_Handler = (void*)HardFault_Handler,
};

void NMI_Handler() {
    while (1) {}
}

void HardFault_Handler() {
    while (1) {}
}

void Reset_Handler() {
    // Enable the RAM
    NRF_POWER->RAMON |= (1u << 1 | 1u << 0);
    NRF_POWER->RAMONB |= (1u << 1 | 1u << 0);

    uint32_t* init_values_ptr = &_etext;
    uint32_t* data_ptr = &_sdata;

    // Copy initialized values from text to data
    if (init_values_ptr != data_ptr) {
        while (data_ptr < &_edata) {
            *data_ptr++ = *init_values_ptr++;
        }
    }

    // Clear the zero initialized segment
    for (uint32_t* bss_ptr = &_sbss; bss_ptr < &_ebss;) {
        *bss_ptr++ = 0;
    }

    main();

    while (1) {}
}