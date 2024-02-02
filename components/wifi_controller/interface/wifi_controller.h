/**
 * @file wifi_controller.h
 * @author hhoang308 (huyhoang3082001@gmail.com)
 * @brief Provides an interface for common Wi-Fi related operation
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WIFI_CONTROLLER_H
#define WIFI_CONTROLLER_H

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

#define ESP_WIFI_SSID CONFIG_ESP_WIFI_SSID
#define ESP_WIFI_PASS CONFIG_ESP_WIFI_PASSWORD
#define ESP_MAXMIMUM_RETRY CONFIG_ESP_MAXIMUM_RETRY

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT BIT1

static const char *TAG = "wifi controller";

static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

void wifi_init_sta(void);

#endif