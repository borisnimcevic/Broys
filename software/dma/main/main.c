#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "pin_config.h"

#define TAG "Example"

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

void setDigit(int digit) {
  switch (digit) {
  case 0:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 1);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 0);
    break;
  case 1:
    gpio_set_level(A_LED, 0);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 0);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 0);
    gpio_set_level(G_LED, 0);
    break;
  case 2:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 0);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 1);
    gpio_set_level(F_LED, 0);
    gpio_set_level(G_LED, 1);
    break;
  case 3:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 0);
    gpio_set_level(G_LED, 1);
    break;
  case 4:
    gpio_set_level(A_LED, 0);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 0);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 1);
    break;
  case 5:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 0);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 1);
    break;
  case 6:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 0);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 1);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 1);
    break;
  case 7:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 0);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 0);
    gpio_set_level(G_LED, 0);
    break;
  case 8:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 1);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 1);
    break;
  case 9:
    gpio_set_level(A_LED, 1);
    gpio_set_level(B_LED, 1);
    gpio_set_level(C_LED, 1);
    gpio_set_level(D_LED, 1);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 1);
    gpio_set_level(G_LED, 1);
    break;
  default:
    gpio_set_level(A_LED, 0);
    gpio_set_level(B_LED, 0);
    gpio_set_level(C_LED, 0);
    gpio_set_level(D_LED, 0);
    gpio_set_level(E_LED, 0);
    gpio_set_level(F_LED, 0);
    gpio_set_level(G_LED, 0);
    break;
  }
}

void setPlace(const int place) {
  switch (place) {
  case 0:
    gpio_set_level(DIGI0, 1);
    gpio_set_level(DIGI1, 0);
    gpio_set_level(DIGI2, 0);
    gpio_set_level(DIGI3, 0);
    break;
  case 1:
    gpio_set_level(DIGI0, 0);
    gpio_set_level(DIGI1, 1);
    gpio_set_level(DIGI2, 0);
    gpio_set_level(DIGI3, 0);
    break;
  case 2:
    gpio_set_level(DIGI0, 0);
    gpio_set_level(DIGI1, 0);
    gpio_set_level(DIGI2, 1);
    gpio_set_level(DIGI3, 0);
    break;
  case 3:
    gpio_set_level(DIGI0, 0);
    gpio_set_level(DIGI1, 0);
    gpio_set_level(DIGI2, 0);
    gpio_set_level(DIGI3, 1);
    break;
  default:
    gpio_set_level(DIGI0, 0);
    gpio_set_level(DIGI1, 0);
    gpio_set_level(DIGI2, 0);
    gpio_set_level(DIGI3, 0);
    break;
  }
}

void app_main(void) {
  // LED stuff
  initGPIOs();
  clearLED();
  setDigit(1);
  setPlace(0);
  int digit = 0;
  int place = 0;
  while (1) {
    setDigit(digit);
    setPlace(place);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digit++;
    // digit %= 10;
    digit %= 4;
    place++;
    place %= 4;
  }
}
