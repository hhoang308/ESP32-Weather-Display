#include "display_task.h"

static const char* TAG = "display task";

TaskHandle_t get_weather_to_display_handler;

void weather_to_display_task(void* pvParameters) {
    ESP_LOGI(TAG, "ESP32_WEATHER_DISPLAY_TASK");
    ESP_LOGI(TAG, "stack when init: %d", uxTaskGetStackHighWaterMark(get_weather_to_display_handler));

    vTaskDelete(NULL);
}