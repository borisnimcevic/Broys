#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_async_memcpy.h"
#include "esp_log.h"
#include "esp_system.h"
#include "pin_config.h"

#define ARR_SIZE 1000

#define TAG "Example"
static uint8_t src_buf[ARR_SIZE];
static uint8_t dst_buf[ARR_SIZE];

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

void async_memcpy_callback(void *arg) {
  ESP_LOGI(TAG, "Async memcpy completed successfully");
}

void app_main(void) {
  // LED stuff
  initGPIOs();
  clearLED();
  gpio_set_level(DIGI2, 1);
  // int state = 0;

  // DMA stuff
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  uint32_t src_int = 0x00000610;
  uint32_t dst_int = 0;

  for (size_t i = 0; i < ARR_SIZE; i++) {
    src_buf[i] = esp_random() % 256;
  } // Copy source buffer to destination buffer asynchronously

  // Initialize async memcpy driver
  async_memcpy_config_t config = ASYNC_MEMCPY_DEFAULT_CONFIG();
  async_memcpy_t driver = NULL;
  ESP_ERROR_CHECK(esp_async_memcpy_install(
      &config, &driver)); // install driver, return driver handle

  // uint32_t *gpio_out_set = (uint32_t *)GPIO_OUT_W1TS_REG;
  // uint32_t *gpio_out_clear = (uint32_t *)GPIO_OUT_W1TC_REG;

  // int i = 0;
  // *gpio_out |= (1 << C_LED);
  while (1) {
    // *gpio_out |= (1 << C_LED);
    // printf("GPIO_OUT_REG [0x%08x] is 0x%08x\n", GPIO_OUT_REG, *gpio_out);
    //
    // printf("src[%d] = %d, dest[%d] = %d \n", i, src_buf[i], i, dst_buf[i]);
    // i++;
    // i %= ARR_SIZE;
    // vTaskDelay(1000 / portTICK_PERIOD_MS);

    // *gpio_out &= ~(1 << C_LED);
    // printf("src[%d] = %d, dest[%d] = %d \n", i, src_buf[i], i, dst_buf[i]);
    // i++;
    // i %= ARR_SIZE;
    // printf("GPIO_OUT_REG [0x%08x] is 0x%08x\n", GPIO_OUT_REG, *gpio_out);

    esp_err_t ret = esp_async_memcpy(driver, gpio_out, &src_int,
                                     2, NULL, NULL);

    if (ret != ESP_OK) {
      ESP_LOGE(TAG, "Async memcpy failed: %s", esp_err_to_name(ret));
    }
    else{
      ESP_LOGI(TAG, "Async memcpy started");
    }

    printf("src = 0x%08x , dst = 0x%08x \n", src_int, *gpio_out);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
