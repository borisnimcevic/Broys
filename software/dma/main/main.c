#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "pin_config.h"

void clearLED(void) {
  gpio_set_level(DIGI0, 0);
  gpio_set_level(DIGI1, 0);
  gpio_set_level(DIGI2, 0);
  gpio_set_level(DIGI3, 0);

  gpio_set_level(A_LED, 0);
  gpio_set_level(B_LED, 0);
  gpio_set_level(C_LED, 0);
  gpio_set_level(D_LED, 0);
  gpio_set_level(E_LED, 0);
  gpio_set_level(F_LED, 0);
  gpio_set_level(G_LED, 0);
}

void app_main(void) {
  // LED stuff
  initGPIOs();
  clearLED();
  gpio_set_level(DIGI2, 1);
  // int state = 0;

  // DMA stuff
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  // uint32_t *gpio_out_set = (uint32_t *)GPIO_OUT_W1TS_REG;
  // uint32_t *gpio_out_clear = (uint32_t *)GPIO_OUT_W1TC_REG;

  while (1) {
    // state ^= 1;
    // gpio_set_level(F_LED, state);
    // printf("The sate of LED is %d\n", state);
    // *gpio_out_set |= (1 << 1);
    *gpio_out |= (1 << C_LED);
    printf("GPIO_OUT_REG [0x%08x] is 0x%08x\n", GPIO_OUT_REG, *gpio_out);
    // printf("GPIO_OUT_W1TS_REG [0x%08x] is 0x%08x\n", GPIO_OUT_W1TS_REG,
    // *gpio_out_set);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    *gpio_out &= ~(1 << C_LED);
    // *gpio_out_clear |= (1 << 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
