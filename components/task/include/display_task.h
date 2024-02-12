#ifndef DISPLAY_TASK_H
#define DISPLAY_TASK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"

extern TaskHandle_t get_weather_to_display_handler;

void weather_to_display_task(void* pvParameters);

#endif