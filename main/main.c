#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_err.h"

#include "tasksHandler.h"
#include "wifiHandler.h"


void app_main(void)
{
    ConnectToWifi();

    vTaskDelay(pdMS_TO_TICKS(100));
    // Create tasks
    xTaskCreatePinnedToCore(MainThread, "Main_Thread", 4096, NULL, 2, NULL, tskNO_AFFINITY);

}