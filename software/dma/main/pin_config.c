#include "pin_config.h"
#include "stdint.h"

void initGPIOs(void) {
  uint64_t bit_mask =
      0; /*!< GPIO pin: set with bit mask, each bit maps to a GPIO */
  for (uint8_t i = 0; i < sizeof(digit_pins) / sizeof(gpio_num_t); i++) {
    bit_mask |= (1ULL << digit_pins[i]);
  }
  for (uint8_t i = 0; i < sizeof(led_pins) / sizeof(gpio_num_t); i++) {
    bit_mask |= (1ULL << led_pins[i]);
  }
  gpio_config_t io_conf;
  io_conf.intr_type = GPIO_INTR_DISABLE;
  io_conf.mode = GPIO_MODE_OUTPUT;
  io_conf.pin_bit_mask = bit_mask;
  io_conf.pull_down_en = 0;
  io_conf.pull_up_en = 0;
  gpio_config(&io_conf);
}

void setPlace(const uint8_t place) {
  const uint8_t mask = (place <= 3) ? (1 << place) : 0;
  const uint8_t val = mask & 0x0F;
  gpio_set_level(DIGI0, val & 0x1);
  gpio_set_level(DIGI1, val & 0x2);
  gpio_set_level(DIGI2, val & 0x4);
  gpio_set_level(DIGI3, val & 0x8);
}

void setDigit(const uint8_t digit) {
  const uint8_t *val = (digit <= 9) ? values[digit] : values[10];
  for (int i = 0; i < 7; i++) {
    gpio_set_level(led_pins[i], val[i]);
  }
}

void clearLED(void) {
  setPlace(PIN_MAX_DIGIT + 1);
  setDigit(PIN_MAX_NUMBER + 1);
}
