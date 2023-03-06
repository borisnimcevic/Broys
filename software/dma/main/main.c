#include "esp_attr.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "pin_config.h"

#define TAG "Example"

// #define TIMER_INTERVAL_US 1000000
#define TIMER_INTERVAL_US    5000

void IRAM_ATTR timer_isr(void *arg) {
  static uint8_t digit = 0;
  static uint8_t place = 0;

  setDigit(digit);
  setPlace(place);

  digit++;
  place++;

  digit%=4;
  place%=4;
}

void app_main(void) {
  initGPIOs();
  clearLED();
  setDigit(0);
  setPlace(0);

  esp_timer_create_args_t timer_args = {.callback = timer_isr,
                                        .arg = NULL,
                                        .dispatch_method = ESP_TIMER_TASK,
                                        .name = "my_timer"};

  esp_timer_handle_t timer;

  esp_timer_create(&timer_args, &timer);
  esp_timer_start_periodic(timer, TIMER_INTERVAL_US);

  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
