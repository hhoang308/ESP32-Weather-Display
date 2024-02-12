idf_component_register(SRCS "src/weather_task.c" "src/display_task.c"
                    INCLUDE_DIRS "include"
                    REQUIRES freertos wifi_controller esp-tls log json)