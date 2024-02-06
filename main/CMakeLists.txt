idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES esp_wifi cxx newlib freertos esp_hw_support heap log soc hal esp_rom esp_common esp_system esp_event nvs_flash)