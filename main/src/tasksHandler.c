#include "tasksHandler.h"


#define ESP_CONFIG_IP_ADDRESS_A CONFIG_IP_ADDRESS_A
#define ESP_CONFIG_IP_ADDRESS_B CONFIG_IP_ADDRESS_B
#define ESP_CONFIG_IP_ADDRESS_C CONFIG_IP_ADDRESS_C

const char *TAG = "Ets2 Controller Box";

bool ConfigIP(ip_addr_t* targetIP, const char* ip_address) {
    if (ipaddr_aton(ip_address, targetIP)) {
        if (targetIP->u_addr.ip4.addr != 0)
            return true;
    }
    return false;
}

void MainThread(void *arg) {
    printf("Start MainTask thread.\n");
    bool Status_IP_A;
    bool Status_IP_B;
    bool Status_IP_C;

    ip_addr_t targetIP_A;
    ip_addr_t targetIP_B;
    ip_addr_t targetIP_C;
    bool Has_IP_A = ConfigIP(&targetIP_A, ESP_CONFIG_IP_ADDRESS_A);
    bool Has_IP_B = ConfigIP(&targetIP_B, ESP_CONFIG_IP_ADDRESS_B);
    bool Has_IP_C = ConfigIP(&targetIP_C, ESP_CONFIG_IP_ADDRESS_C);
    ESP_LOGI("NETWORK", "Has IP A: %d (%s)", Has_IP_A, ESP_CONFIG_IP_ADDRESS_A);
    ESP_LOGI("NETWORK", "Has IP B: %d (%s)", Has_IP_B, ESP_CONFIG_IP_ADDRESS_B);
    ESP_LOGI("NETWORK", "Has IP C: %d (%s)", Has_IP_C, ESP_CONFIG_IP_ADDRESS_C);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
        /* Test. TODO: Create a logic with the 3 IPs */
        printf("Call Ping.\n");
        PingCmd(targetIP_A, &Status_IP_A);
        vTaskDelay(pdMS_TO_TICKS(5000));
        if (Status_IP_A) {
            ESP_LOGI("NETWORK", "Positive Response A");
        } else {
            ESP_LOGI("NETWORK", "Negative Response A");
        }
    }
}