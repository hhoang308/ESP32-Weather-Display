#include "weather_task.h"

TaskHandle_t get_current_weather_task_handler;

static const char* TAG = "weather task";

static const char* request = "GET " WEB_URL " HTTP/1.0\r\n"
                             "Host: " WEB_SERVER "\r\n"
                             "User-Agent: esp-idf/1.0 esp32\r\n";

static void https_get(const char* url, const char* request, char* buf){
    ESP_LOGI(TAG, "start connect to URL %s", WEB_URL);
    struct esp_tls* tls = esp_tls_conn_http_new(url, NULL);

    if (tls != NULL) {
        ESP_LOGI(TAG, "Connection established...");
    } else {
        ESP_LOGE(TAG, "Connection failed...");
        goto exit;
    }
    int ret, len;
    size_t written_bytes = 0;
    ESP_LOGI(TAG, "start write request: %s to URL", request);
    do {
        ret = esp_tls_conn_write(tls, request + written_bytes, strlen(request) - written_bytes);
        if (ret >= 0) {
            ESP_LOGI(TAG, "%d bytes written", ret);
            written_bytes += ret;
        } else if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {
            ESP_LOGE(TAG, "esp_tls_conn_write  returned 0x%x", ret);
            goto exit;
        }
    } while (written_bytes < strlen(request));

    ESP_LOGI(TAG, "Reading HTTP response...");

    int offset = 0;

    do {
        char tmp_buf[64];

        len = sizeof(tmp_buf) - 1;
        bzero(tmp_buf, sizeof(tmp_buf));
        ret = esp_tls_conn_read(tls, (char*)tmp_buf, len);

        if (ret == MBEDTLS_ERR_SSL_WANT_WRITE || ret == MBEDTLS_ERR_SSL_WANT_READ)
            continue;

        if (ret < 0) {
            ESP_LOGE(TAG, "esp_tls_conn_read  returned -0x%x", -ret);
            break;
        }

        if (ret == 0) {
            ESP_LOGI(TAG, "connection closed");
            break;
        }

        len = ret;
        ESP_LOGD(TAG, "%d bytes read", len);

        for (int i = 0; i < len; i++) {
            buf[i + offset] = tmp_buf[i];
        }
        offset += len;

    } while (1);

    buf[offset] = 0;
exit:
    esp_tls_conn_delete(tls);
}

void get_current_weather_task(void* pvParameters) {
    ESP_LOGI(TAG, "ESP32_GET_CURRENT_WEATHER_TASK");
    ESP_LOGI(TAG, "stack when init: %d", uxTaskGetStackHighWaterMark(get_current_weather_task_handler));
    
    char buf[1024 * 15];
    https_get(WEB_URL, request, buf);
    
    ESP_LOGI(TAG, "stack after finish: %d", uxTaskGetStackHighWaterMark(get_current_weather_task_handler));
    vTaskDelete(NULL);
}

