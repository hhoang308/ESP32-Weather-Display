#ifndef WEATHER_TASK_H
#define WEATHER_TASK_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "wifi_controller.h"
#include "esp_tls.h"
#include "mbedtls/platform.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/esp_debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "cJSON.h"

#define WEB_SERVER CONFIG_WEB_SERVER
#define WEB_PORT CONFIG_WEB_PORT
#define WEB_URL "https://api.openweathermap.org/data/3.0/onecall?lat=33.44&lon=-94.04&appid=" CONFIG_API_KEY "&units=metric"

typedef struct Forecasts {
    time_t time;
    char summary[50];
    char icon[20];
    double temperatureMax;
    double temperatureMin;
    double humidity;
    int pressure;
} Forecast;

// const uint8_t server_root_cert_pem_start[] asm("_binary_server_root_cert_pem_start");
// const uint8_t server_root_cert_pem_end[] asm("_binary_server_root_cert_pem_end");

extern TaskHandle_t get_current_weather_task_handler;

void get_current_weather_task(void* pvParameters);

#endif 