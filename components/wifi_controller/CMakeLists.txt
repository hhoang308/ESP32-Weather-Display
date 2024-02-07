idf_component_register(SRCS "wifi_controller.c"
                    INCLUDE_DIRS "include"
                    REQUIRES esp_wifi cxx newlib freertos esp_hw_support heap log soc hal esp_rom esp_common esp_system esp_event nvs_flash)