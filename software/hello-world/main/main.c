#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "pin_config.h"

// TODO: Document in readme that these can't be used
// #define DIV0 12
// #define DIV1 13
// gpio_set_direction(DIV0 , GPIO_MODE_OUTPUT);
// gpio_set_direction(DIV1, GPIO_MODE_OUTPUT);
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

TaskHandle_t led_col_task_handle;
const int delay = 4;

// void led_col_task(void *arg) {
void led_col_task(void *arg) {
  uint8_t col = 0;
  while (1) {
    // ESP_LOGI("Boris","switch -> %d", col);
    clearLED();
    // vTaskDelay(delay / portTICK_PERIOD_MS);
    switch (col) {
    case 0:
      gpio_set_level(B_LED, 1);
      gpio_set_level(C_LED, 1);
      gpio_set_level(DIGI0, 1);
      break;
    case 1:
      gpio_set_level(A_LED, 1);
      gpio_set_level(B_LED, 1);
      gpio_set_level(D_LED, 1);
      gpio_set_level(E_LED, 1);
      gpio_set_level(G_LED, 1);
      gpio_set_level(DIGI1, 1);
      break;
    case 2:
      gpio_set_level(A_LED, 1);
      gpio_set_level(B_LED, 1);
      gpio_set_level(C_LED, 1);
      gpio_set_level(D_LED, 1);
      gpio_set_level(G_LED, 1);
      gpio_set_level(DIGI2, 1);
      break;
    case 3:
      gpio_set_level(B_LED, 1);
      gpio_set_level(C_LED, 1);
      gpio_set_level(F_LED, 1);
      gpio_set_level(G_LED, 1);
      gpio_set_level(DIGI3, 1);
      break;
    default:
      break;
    }
    vTaskDelay(delay / portTICK_PERIOD_MS);
    col++;
    col %= 4;
  }
}

void app_main(void) {
  initGPIOs();

  // Create a task for each LED column
  xTaskCreate(led_col_task, "LED", 2048, NULL, 10,
              &led_col_task_handle);

  // vTaskStartScheduler();
}
