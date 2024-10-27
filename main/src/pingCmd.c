#include "pingCmd.h"

void PingSuccess(esp_ping_handle_t hdl, void *args) {
    ESP_LOGI(TAG, "PingSuccess called.");
    uint8_t ttl;
    uint16_t seqno;
    uint32_t elapsed_time, recv_len;
    ip_addr_t target_addr;
    esp_ping_get_profile(hdl, ESP_PING_PROF_SEQNO, &seqno, sizeof(seqno));
    esp_ping_get_profile(hdl, ESP_PING_PROF_TTL, &ttl, sizeof(ttl));
    esp_ping_get_profile(hdl, ESP_PING_PROF_IPADDR, &target_addr, sizeof(target_addr));
    esp_ping_get_profile(hdl, ESP_PING_PROF_SIZE, &recv_len, sizeof(recv_len));
    esp_ping_get_profile(hdl, ESP_PING_PROF_TIMEGAP, &elapsed_time, sizeof(elapsed_time));
    printf("%ld bytes from %s icmp_seq=%d ttl=%d time=%ld ms\n",
           recv_len, inet_ntoa(target_addr.u_addr.ip4), seqno, ttl, elapsed_time);
    esp_ping_stop(hdl);
    esp_ping_delete_session(hdl);
    *(bool *)args = true;
}

void PingTimeout(esp_ping_handle_t hdl, void *args) {
    ESP_LOGI(TAG, "PingTimeout called.");
    uint16_t seqno;
    ip_addr_t target_addr;
    esp_ping_get_profile(hdl, ESP_PING_PROF_SEQNO, &seqno, sizeof(seqno));
    esp_ping_get_profile(hdl, ESP_PING_PROF_IPADDR, &target_addr, sizeof(target_addr));
    printf("From %s icmp_seq=%d timeout\n", inet_ntoa(target_addr.u_addr.ip4), seqno);
    esp_ping_stop(hdl);
    esp_ping_delete_session(hdl);
}

void PingEnd(esp_ping_handle_t hdl, void *args) {
    ESP_LOGI(TAG, "PingEnd called.");
    uint32_t transmitted;
    uint32_t received;
    uint32_t total_time_ms;

    esp_ping_get_profile(hdl, ESP_PING_PROF_REQUEST, &transmitted, sizeof(transmitted));
    esp_ping_get_profile(hdl, ESP_PING_PROF_REPLY, &received, sizeof(received));
    esp_ping_get_profile(hdl, ESP_PING_PROF_DURATION, &total_time_ms, sizeof(total_time_ms));
    printf("%ld packets transmitted, %ld received, time %ldms\n", transmitted, received, total_time_ms);
    esp_ping_stop(hdl);
    esp_ping_delete_session(hdl);
}

void PingCmd(ip_addr_t target_addr, bool* ping_res) {
    ESP_LOGI(TAG, "PingCmd called.");
    esp_ping_config_t ping_config = ESP_PING_DEFAULT_CONFIG();
    ping_config.timeout_ms = 1000,
    ping_config.target_addr = target_addr;          // target IP address
    ping_config.count = 3;

    *ping_res = false;
    /* set callback functions */
    esp_ping_callbacks_t cbs;
    cbs.on_ping_success = PingSuccess;
    cbs.on_ping_timeout = PingTimeout;
    cbs.on_ping_end = PingEnd;
    cbs.cb_args = ping_res;
    //cbs.cb_args = "callback";  // arguments that feeds to all callback functions, TODO: Verify to add the bool type here

    esp_ping_handle_t ping;
    esp_ping_new_session(&ping_config, &cbs, &ping);
    esp_ping_start(ping);
}