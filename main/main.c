#include <stdio.h>
#include "esp_log.h"
#include "esp_event.h"
#include "nvs_flash.h"

/**
 * @brief It is the main funtion for ESP32-Weather-Display.
 * 
 */    
static const char* TAG = "main";

void app_main(void){
    ESP_LOGD(TAG, "app_main started");
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}