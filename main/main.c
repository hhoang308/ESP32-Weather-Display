#include <stdio.h>
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "wifi_controller.h"
#include "display_task.h"
#include "weather_task.h"

static const char* TAG = "main";

/**
 * @brief It is the main funtion for ESP32-Weather-Display.
 * 
 */    

void app_main(void){
    ESP_LOGI(TAG, "app_main started");
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    wifi_init_sta();
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "Wifi connected, start task");
        xTaskCreate(&get_current_weather_task, "get_current_weather_task", 1024 * 20, NULL, 5, &get_current_weather_task_handler);
        xTaskCreate(&weather_to_display_task, "weather_to_display_task", 1024 * 8, NULL, 5, &get_weather_to_display_handler);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Wifi failed to connect, do nothing");
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
                 
}