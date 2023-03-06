#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "pin_config.h"

#define TAG "Example"

void app_main(void) {
  initGPIOs();
  clearLED();
  setDigit(1);
  setPlace(0);
  int digit = 0;
  uint8_t place = 0;

  while (1) {
    setDigit(digit);
    setPlace(place);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digit++;
    // digit %= 10;
    digit %= 4;
    place++;
    place %= 4;
  }
}
