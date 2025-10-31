#include <nrf.h>
#include <stdbool.h>
#include <stdint.h>

int main() {
    const uint32_t pin_number = 0;

    // Set the pin to output
    NRF_GPIO->DIRSET |= (1 << pin_number);
    bool state = false;

    while (true) {
        state = !state;
        if (state) {
            NRF_GPIO->OUTSET |= (1 << pin_number);
        } else {
            NRF_GPIO->OUTCLR |= (1 << pin_number);
        }
        for (volatile int i = 0; i < 1000000; ++i) {}
    }
}