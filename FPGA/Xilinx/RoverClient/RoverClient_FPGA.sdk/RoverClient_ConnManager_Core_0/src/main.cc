/*
 * Main Rover Connection Application
 */


#ifndef __cplusplus
#define __cplusplus
#endif /* __cplusplus */

#include "xparameters.h"
#include "netif/xadapter.h"
#include "xil_printf.h"

#include "platform.h"
#include "platform_config.h"
#include "client.h"

int main()
{
	/* MAC address of the board. Must be unique per board. */
	unsigned char mac_ethernet_address[] = { 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

	/* Allocate local memory */
	struct netif *netif, server_netif;
	struct ip_addr ipaddr, netmask, gw;
	netif = &server_netif;

	/* Initialize platform */
	init_platform();

	/* initialize local IP addresses */
	IP4_ADDR(&ipaddr, 192, 0, 0, 10);
	IP4_ADDR(&netmask, 255, 255, 255, 0);
	IP4_ADDR(&gw, 192, 0, 0, 1);
	lwip_init();

	/* Add network interface to the netif_list, and set it as default */
	if (!xemac_add(netif, &ipaddr, &netmask, &gw, mac_ethernet_address, XPAR_XEMACPS_0_BASEADDR)) {
		xil_printf("Error adding N/W interface\r\n");
		return -1;
	}
	netif_set_default(netif);

	/* specify that the network if is up */
	netif_set_up(netif);

	/* connect to the server */
	Client c({192, 0, 0, 1}, 8088);
	c.connect();
	while (!c.connected()) {
		xil_printf("Connection Failed\r\n");
		c.connect();
	}
	xil_printf("C\r\n");

	while (1) {
		xemacif_input(netif);
		c.transfer_data();
	}

	/* never reached */
	cleanup_platform();

	return 0;
}
