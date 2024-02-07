#ifndef WEATHER_TASK_H
#define WEATHER_TASK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#define WEB_SERVER CONFIG_WEB_SERVER
#define WEB_PORT CONFIG_WEB_PORT
#define WEB_URL "https://api.darksky.net/forecast/" CONFIG_DARKSKY_API_KEY "/" CONFIG_LATITUDE "," CONFIG_LONGITUDE "?lang=en&exclude=hourly,flag,minutely&units=auto"

typedef struct Forecasts {
    time_t time;
    char summary[50];
    char icon[20];
    double temperatureMax;
    double temperatureMin;
    double humidity;
    int pressure;
} Forecast;

void get_current_weather_task(void* pvParameters);

#endif 