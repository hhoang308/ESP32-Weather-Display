#include "weather_task.h"

TaskHandle_t get_current_weather_task_handler;

static const char* TAG = "weather task";

static void http_get(const char* url, const char* request, char* buf){

}

void get_current_weather_task(void* pvParameters) {
    ESP_LOGI(TAG, "ESP32_GET_CURRENT_WEATHER_TASK");
    ESP_LOGI(TAG, "stack when init: %d", uxTaskGetStackHighWaterMark(get_current_weather_task_handler));

    vTaskDelete(NULL);
}

