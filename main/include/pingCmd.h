#ifndef PINGCMD_H
#define PINGCMD_H

#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "lwip/inet.h"
#include "lwip/netdb.h"
#include "lwip/sockets.h"
#include "esp_console.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "argtable3/argtable3.h"
#include "ping/ping_sock.h"

#include "tasksHandler.h"
#include "wifiHandler.h"

extern void PingCmd(const ip_addr_t target_addr, bool* ping_res);

#endif // PINGCMD_H