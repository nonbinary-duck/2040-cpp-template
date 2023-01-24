#include <stdio.h>

#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>

#include "src/utils.hpp"


/**
 * @brief Called when the program is launched
 * 
 * @param argc Count of command-line arguments
 * @param argv Args, zero is the name of the program
 * @return int An error code
 */
int main(int argc, char *argv[])
{
    stdio_init_all();

    while (true)
    {    
        printf("LED on\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
        printf("LED off\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(1000);
    }

    return 0;
}
