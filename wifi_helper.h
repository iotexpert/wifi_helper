#pragma once

#include <stdbool.h>
#include "cy_wcm.h"

typedef enum {
    WIFI_HELPER_SUCCESS,
    WIFI_HELPER_SUCCESS_FAILURE,
    WIFI_HELPER_BUFFER_OVERFLOW,

} wifi_helper_rslt_t;

char *wifi_mac_to_string(cy_wcm_mac_t mac);

char *wifi_ntoa(cy_wcm_ip_address_t *ip_addr);

cy_wcm_ip_address_t wifi_make_cywcm_ipv4(int a,int b, int c, int d);

inline uint32_t wifi_make_ipv4(int a,int b, int c, int d)
{
    return ((((uint32_t) d) << 24) | (((uint32_t) c) << 16) | (((uint32_t) b) << 8) |((uint32_t) a));
}
