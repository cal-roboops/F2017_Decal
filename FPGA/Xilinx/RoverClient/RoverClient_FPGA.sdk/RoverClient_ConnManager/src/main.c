/*
 * main.c
 *
 *  Created on: Jan 26, 2018
 *      Author: PC
 */

#include <stdio.h>
#include "xparameters.h"
#include "netif/xadapter.h"
#include "platform.h"
#include "platform_config.h"
#include "xil_printf.h"

#include "lwip/init.h"
#include "lwipopts.h"

#include "client.h"

void tcp_fasttmr(void);
void tcp_slowtmr(void);

extern volatile int TcpFastTmrFlag;
extern volatile int TcpSlowTmrFlag;

void print_ip(char *msg, struct ip_addr *ip)
{
    print(msg);
    xil_printf("%d.%d.%d.%d\r\n", ip4_addr1(ip), ip4_addr2(ip),
			ip4_addr3(ip), ip4_addr4(ip));
}

void print_ip_settings(struct ip_addr *ip, struct ip_addr *mask, struct ip_addr *gw)
{
    print_ip("Board IP:       ", ip);
    print_ip("Netmask :       ", mask);
    print_ip("Gateway :       ", gw);
}

int main()
{
	/* the mac address of the board. this should be unique per board */
	unsigned char mac_ethernet_address[] = { 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

	/* allocate local memory */
	struct netif *netif, server_netif;
	struct ip_addr ipaddr, netmask, gw;
	netif = &server_netif;

	/* initialize platform */
	init_platform();

	/* initialize local IP addresses */
	IP4_ADDR(&ipaddr, 192, 0, 0, 10);
	IP4_ADDR(&netmask, 255, 255, 255, 0);
	IP4_ADDR(&gw, 192, 0, 0, 1);
    print_ip_settings(&ipaddr, &netmask, &gw);

	lwip_init();

	/* Add network interface to the netif_list, and set it as default */
	if (!xemac_add(netif, &ipaddr, &netmask, &gw, mac_ethernet_address, PLATFORM_EMAC_BASEADDR)) {
		xil_printf("Error adding N/W interface\r\n");
		return -1;
	}
	netif_set_default(netif);

	/* specify that the network if is up */
	netif_set_up(netif);

	/* now enable interrupts */
	platform_enable_interrupts();

	/* setup server connection info */
	struct conn_info serv_conn;
	serv_conn.port = 8088;
	IP4_ADDR(&serv_conn.ipaddr, 192, 0, 0, 1);

	/* connect to the server */
	client_connect(&serv_conn);

	while (1) {
		if (TcpFastTmrFlag) {
			tcp_fasttmr();
			TcpFastTmrFlag = 0;
		}

		if (TcpSlowTmrFlag) {
			tcp_slowtmr();
			TcpSlowTmrFlag = 0;
		}

		if (client_connected() && client_connection_lost(&serv_conn)) {
			client_abort(&serv_conn);
			client_connect(&serv_conn);
		}

		xemacif_input(netif);
		transfer_data();
	}

    /* never reached */
    cleanup_platform();

	return 0;
}
