#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "pin_config.h"

void clearLED(void){
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

void app_main(void)
{
  // gpio_set_direction(DIGI0, GPIO_MODE_OUTPUT);
  // gpio_set_direction(DIGI1, GPIO_MODE_OUTPUT);
  // gpio_set_direction(DIGI2, GPIO_MODE_OUTPUT);
  // gpio_set_direction(DIGI3, GPIO_MODE_OUTPUT);
  // gpio_set_direction(A_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(B_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(C_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(D_LED, GPIO_MODE_OUTPUT);
  // // gpio_set_direction(E_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(F_LED, GPIO_MODE_OUTPUT);
  // // gpio_set_direction(G_LED, GPIO_MODE_OUTPUT);
  // //
  // gpio_config_t io_conf;
  // io_conf.intr_type = GPIO_INTR_DISABLE;
  // io_conf.mode = GPIO_MODE_OUTPUT;
  // io_conf.pin_bit_mask = (1ULL<<DIGI0);
  // io_conf.pull_down_en = 0;
  // io_conf.pull_up_en = 0;
  // gpio_config(&io_conf);

  // gpio_config_t io_conf1;
  // io_conf1.intr_type = GPIO_INTR_DISABLE;
  // io_conf1.mode = GPIO_MODE_OUTPUT;
  // io_conf1.pin_bit_mask = (1ULL<<E_LED);
  // io_conf1.pull_down_en = 0;
  // io_conf1.pull_up_en = 0;
  // gpio_config(&io_conf1);


  // gpio_config_t io_conf2;
  // io_conf2.intr_type = GPIO_INTR_DISABLE;
  // io_conf2.mode = GPIO_MODE_OUTPUT;
  // io_conf2.pin_bit_mask = (1ULL<<G_LED);
  // io_conf2.pull_down_en = 0;
  // io_conf2.pull_up_en = 0;
  // gpio_config(&io_conf2);

  // TODO: Document in readme that these can't be used
  // #define DIV0 12 
  // #define DIV1 13 
  // gpio_set_direction(DIV0 , GPIO_MODE_OUTPUT);
  // gpio_set_direction(DIV1, GPIO_MODE_OUTPUT);

  initGPIOs();
  clearLED();

  const int delay = 500;

  while(1){
    clearLED();
    gpio_set_level(A_LED, 1);
    gpio_set_level(DIGI0, 1);
    vTaskDelay(delay /portTICK_PERIOD_MS);

    clearLED();
    gpio_set_level(A_LED, 1);
    gpio_set_level(DIGI1, 1);
    vTaskDelay(delay /portTICK_PERIOD_MS);

    clearLED();
    gpio_set_level(A_LED, 1);
    gpio_set_level(DIGI2, 1);
    vTaskDelay(delay /portTICK_PERIOD_MS);

    clearLED();
    gpio_set_level(A_LED, 1);
    gpio_set_level(DIGI3, 1);
    vTaskDelay(delay /portTICK_PERIOD_MS);
  }
}
