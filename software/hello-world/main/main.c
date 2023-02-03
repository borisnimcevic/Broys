#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define DIGI0 21 
#define DIGI1 3 
#define DIGI2 10 
#define DIGI3 9 

#define A_LED 0 
#define B_LED 1 
#define C_LED 4 
#define D_LED 5 
#define E_LED 6 
#define F_LED 7 
#define G_LED 20 

// #define DIV0 12 
// #define DIV1 13 

void app_main(void)
{
  // gpio_set_direction(DIGI0, GPIO_MODE_OUTPUT);
  gpio_set_direction(DIGI1, GPIO_MODE_OUTPUT);
  gpio_set_direction(DIGI2, GPIO_MODE_OUTPUT);
  gpio_set_direction(DIGI3, GPIO_MODE_OUTPUT);
  gpio_set_direction(A_LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(B_LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(C_LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(D_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(E_LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(F_LED, GPIO_MODE_OUTPUT);
  // gpio_set_direction(G_LED, GPIO_MODE_OUTPUT);
  //
  gpio_config_t io_conf;
  io_conf.intr_type = GPIO_INTR_DISABLE;
  io_conf.mode = GPIO_MODE_OUTPUT;
  io_conf.pin_bit_mask = (1ULL<<DIGI0);
  io_conf.pull_down_en = 0;
  io_conf.pull_up_en = 0;
  gpio_config(&io_conf);

  gpio_config_t io_conf1;
  io_conf1.intr_type = GPIO_INTR_DISABLE;
  io_conf1.mode = GPIO_MODE_OUTPUT;
  io_conf1.pin_bit_mask = (1ULL<<E_LED);
  io_conf1.pull_down_en = 0;
  io_conf1.pull_up_en = 0;
  gpio_config(&io_conf1);


  gpio_config_t io_conf2;
  io_conf2.intr_type = GPIO_INTR_DISABLE;
  io_conf2.mode = GPIO_MODE_OUTPUT;
  io_conf2.pin_bit_mask = (1ULL<<G_LED);
  io_conf2.pull_down_en = 0;
  io_conf2.pull_up_en = 0;
  gpio_config(&io_conf2);

  // TODO: Document in readme that these can't be used
  // gpio_set_direction(DIV0 , GPIO_MODE_OUTPUT);
  // gpio_set_direction(DIV1, GPIO_MODE_OUTPUT);

  gpio_set_level(DIGI0, 0);
  gpio_set_level(DIGI1, 0);
  gpio_set_level(DIGI2, 1);
  gpio_set_level(DIGI3, 0);

  gpio_set_level(A_LED, 1);
  gpio_set_level(B_LED, 0);
  gpio_set_level(C_LED, 0);
  gpio_set_level(D_LED, 0);
  gpio_set_level(E_LED, 0);
  gpio_set_level(F_LED, 0);
  gpio_set_level(G_LED, 0);

  const int delay = 500;

  while(1){
    vTaskDelay(delay /portTICK_PERIOD_MS);
    gpio_set_level(A_LED, 0);
    vTaskDelay(delay /portTICK_PERIOD_MS);
    gpio_set_level(A_LED, 1);
  }
}
