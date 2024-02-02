#include <stdio.h>
#include "esp_log.h"
#include "esp_event.h"

/**
 * @brief It is the main funtion for ESP32-Weather-Display.
 * 
 */

void app_main(void){
    static const char* TAG = "main";
    ESP_LOGD(TAG, "app_main started");
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
}