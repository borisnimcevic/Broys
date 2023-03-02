#include "pin_config.h"
#include "stdint.h"

void initGPIOs(void){
    uint64_t bit_mask = 0;          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    for(uint8_t i = 0; i< sizeof(display_pins)/sizeof(gpio_num_t); i++){
        bit_mask |= (1ULL<<display_pins[i]);
    }
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = bit_mask;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}

void initIO(gpio_num_t pin){
    uint64_t bit_mask = 0;          /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
    bit_mask |= 1ULL<<pin;
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = bit_mask;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}
