#include "esp_attr.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "pin_config.h"

#define TAG "Example"

#define TIMER_DISPALY_REFRESH_US 5000   // micro seconds
#define TIMER_COUNTER_INCREMENT_MS 1000 // mili seconds

uint8_t number[4] = {0};

void IRAM_ATTR timer_isr(void *arg) {
  static uint8_t place = 0;
  setPlace(place);
  setDigit(number[place]);
  place++;
  place &= 0x03;
}

void counter_task(void *arg) {
  uint32_t counter = 0;
  while (1) {
    counter++;
    uint32_t temp = counter;
    for (int i = 3; i >= 0; i--) {
      number[i] = temp % 10;
      temp /= 10;
    }
    vTaskDelay(pdMS_TO_TICKS(TIMER_COUNTER_INCREMENT_MS));
    printf("counter = %d\n", counter);
  }
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
  esp_timer_start_periodic(timer, TIMER_DISPALY_REFRESH_US);

  xTaskCreate(counter_task, "Counter Task", 2048, NULL, 1, NULL);
  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
