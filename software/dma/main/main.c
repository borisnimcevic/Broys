#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_private/gdma.h"
#include "pin_config.h"

#define ARR_SIZE 1000

#define TAG "Example"

static gdma_channel_handle_t s_tx_channel;

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
  initGPIOs();
  clearLED();
  gpio_set_level(DIGI2, 1);
  gpio_set_level(C_LED, 1);

  // DMA stuff
  // uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  // *gpio_out |= (1 << C_LED);
  // *gpio_out &= ~(1 << C_LED);

  gdma_channel_alloc_config_t tx_channel_config = {
      .flags.reserve_sibling = 0,
      .direction = GDMA_CHANNEL_DIRECTION_TX,
      .sibling_chan = NULL,
  };

  ESP_ERROR_CHECK(gdma_new_channel(&tx_channel_config, &s_tx_channel));
  // gdma_connect(s_tx_channel,GDMA_MAKE_TRIGGER(GDMA_TRIG_PERIPH_UART, 0));
  // gdma_connect(s_tx_channel, GDMA_MAKE_TRIGGER(GDMA_TRIG_PERIPH_DAC, 0));

  while (1) {
    printf("GPIO_OUT_REG = 0x%08x\n", GPIO_OUT_REG);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
