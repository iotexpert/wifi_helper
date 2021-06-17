#include "wifi_helper.h"
#include "cy_wcm.h"
#include <stdio.h>
#include "cy_utils.h"
#include "cy_log.h"

char *wifi_mac_to_string(cy_wcm_mac_t mac)
{
    static char _mac_string[] = "xx:xx:xx:xx:xx:xx";
    sprintf(_mac_string,"%02X:%02X:%02X:%02X:%02X:%02X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
    return _mac_string; 
}


char *wifi_ntoa(cy_wcm_ip_address_t *ip_addr)
{

    static char buff[32];

    switch(ip_addr->version)
    {
        case CY_WCM_IP_VER_V4:
            sprintf(buff,"%d.%d.%d.%d", (uint8_t)ip_addr->ip.v4,
                (uint8_t)(ip_addr->ip.v4 >> 8), (uint8_t)(ip_addr->ip.v4 >> 16),
                (uint8_t)(ip_addr->ip.v4 >> 24));        break;
        case CY_WCM_IP_VER_V6:
            sprintf(buff,"%X:%X:%X:%X", (uint8_t)ip_addr->ip.v6[0],
                (uint8_t)(ip_addr->ip.v6[1]), (uint8_t)(ip_addr->ip.v6[2]),
                (uint8_t)(ip_addr->ip.v6[3]));
        break;
    }
    CY_ASSERT(buff[0] != 0); // SOMETHING should have happened
    return buff;
}


cy_wcm_ip_address_t wifi_make_cywcm_ipv4(int a,int b, int c, int d)
{
    cy_wcm_ip_address_t rval;
    rval.version = CY_WCM_IP_VER_V4;
    rval.ip.v4 = wifi_make_ipv4(a,b,c,d);
    return rval;
}

uint32_t wifi_aton(char *ip_addr)
{
    int a,b,c,d;
    sscanf(ip_addr,"%d.%d.%d.%d",&a,&b,&c,&d);
    return wifi_make_ipv4(a,b,c,d);
}
