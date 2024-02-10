#include "display_task.h"

static const char* TAG = "display task";

void weather_to_display_task(void* pvParameters) {
    ESP_LOGI(TAG, "ESP32_WEATHER_DISPLAY_TASK");
    vTaskDelete(NULL);
}