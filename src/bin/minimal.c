#include <nrf.h>
#include <stdbool.h>
#include <stdint.h>

int main()
{
    while (true)
    {
        for (volatile int i = 0; i < 100000; ++i)
        {
        }
    }
}