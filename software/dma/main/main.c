#include "esp_attr.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_wifi.h"
#include "esp_wifi_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "pin_config.h"
#include "secret_file.h"

#define TAG "Boris"

#define TIMER_DISPALY_REFRESH_US 5000   // micro seconds
#define TIMER_COUNTER_INCREMENT_MS 6000 // mili seconds

#define PLACE_MASK 0x03

#define MAXIMUM_WIFI_RETRY 5

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

#if CONFIG_ESP_WIFI_AUTH_OPEN
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_OPEN
#elif CONFIG_ESP_WIFI_AUTH_WEP
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WEP
#elif CONFIG_ESP_WIFI_AUTH_WPA_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA_WPA2_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WPA2_WPA3_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_ESP_WIFI_AUTH_WAPI_PSK
#define ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WAPI_PSK
#endif

static uint8_t number[4] = {0};

/* FreeRTOS event group to signal when we are connected*/
static EventGroupHandle_t s_wifi_event_group;
static int s_retry_num = 0;

void IRAM_ATTR timer_isr(void *arg) {
  static uint8_t place = 0;
  setPlace(place);
  setDigit(number[place]);
  place = (place + 1) & PLACE_MASK;
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

void time_task(void *arg) {

}
static void event_handler(void *arg, esp_event_base_t event_base,
                          int32_t event_id, void *event_data) {
  if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
    esp_wifi_connect();
  } else if (event_base == WIFI_EVENT &&
             event_id == WIFI_EVENT_STA_DISCONNECTED) {
    if (s_retry_num < MAXIMUM_WIFI_RETRY) {
      esp_wifi_connect();
      s_retry_num++;
      ESP_LOGI(TAG, "retry to connect to the AP, try no.: %d", s_retry_num);
    } else {
      xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
    }
  } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
    ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
    ESP_LOGI(TAG, "got ip: " IPSTR, IP2STR(&event->ip_info.ip));
    s_retry_num = 0;
    xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
  }
}

void setupWifi(void) {
  // Initialize NVS
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
      ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
  // setup wifi

  s_wifi_event_group = xEventGroupCreate();
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_netif_create_default_wifi_sta();

  wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
  ESP_ERROR_CHECK(esp_wifi_init(&cfg));

  esp_event_handler_instance_t instance_any_id;
  esp_event_handler_instance_t instance_got_ip;
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, &instance_any_id));
  ESP_ERROR_CHECK(esp_event_handler_instance_register(
      IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, &instance_got_ip));

  wifi_config_t wifi_config = {
      .sta =
          {
              .ssid = MY_SSID, .password = MY_PASSWORD,
              /* Setting a password implies station will connect to all security
               * modes including WEP/WPA. However these modes are deprecated and
               * not advisable to be used. Incase your Access point doesn't
               * support WPA2, these mode can be enabled by commenting below
               * line */
              // .threshold.authmode = ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD,
              // .threshold.authmode = WIFI_AUTH_OPEN,
              // .sae_pwe_h2e = WPA3_SAE_PWE_BOTH,
          },
  };

  ESP_LOGI(TAG, "config setup");

  ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
  ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
  ESP_ERROR_CHECK(esp_wifi_start());

  ESP_LOGI(TAG, "wifi_init_sta finished.");

  /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or
   * connection failed for the maximum number of re-tries (WIFI_FAIL_BIT). The
   * bits are set by event_handler() (see above) */
  EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                         WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                         pdFALSE, pdFALSE, portMAX_DELAY);

  /* xEventGroupWaitBits() returns the bits before the call returned, hence we
   * can test which event actually happened. */
  if (bits & WIFI_CONNECTED_BIT) {
    ESP_LOGI(TAG, "connected to ap SSID:%s", MY_SSID);
  } else if (bits & WIFI_FAIL_BIT) {
    ESP_LOGI(TAG, "Failed to connect to SSID:%s", MY_SSID);
  } else {
    ESP_LOGE(TAG, "UNEXPECTED EVENT");
  }
}

void app_main(void) {
  // init LEDs
  initGPIOs();
  clearLED();

  setupWifi();

  // init interupt service routine
  esp_timer_create_args_t timer_args = {.callback = timer_isr,
                                        .arg = NULL,
                                        .dispatch_method = ESP_TIMER_TASK,
                                        .name = "my_timer"};

  esp_timer_handle_t timer;
  esp_timer_create(&timer_args, &timer);
  // esp_timer_start_periodic(timer, TIMER_DISPALY_REFRESH_US);

  // create task
  // xTaskCreate(counter_task, "Counter Task", 2048, NULL, 1, NULL);
  xTaskCreate(time_task, "Time Task", 2048, NULL, 1, NULL);
  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
