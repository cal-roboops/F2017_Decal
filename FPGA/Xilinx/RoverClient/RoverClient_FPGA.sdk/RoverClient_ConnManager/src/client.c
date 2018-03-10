/*
 * client.c
 *
 *  Created on: Jan 26, 2018
 *      Author: PC
 */

#include "client.h"
#include <stdio.h>
#include <string.h>

#if defined (__arm__) || defined (__aarch64__)
#include "xil_printf.h"
#endif

uint8_t connected = 0;

int transfer_data() {
	return 0;
}

void print_app_header()
{
	xil_printf("\n\r\n\r-----lwIP TCP echo server ------\n\r");
	xil_printf("TCP packets sent to port 8088 will be echoed back\n\r");
}

err_t recv_callback(void *arg, struct tcp_pcb *tpcb,
                               struct pbuf *p, err_t err)
{
	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p) {
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		return ERR_OK;
	}

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->len);

	/* echo back the payload */
	/* in this case, we assume that the payload is < TCP_SND_BUF */
	if (tcp_sndbuf(tpcb) > p->len) {
		err = tcp_write(tpcb, p->payload, p->len, 1);
	} else {
		xil_printf("no space in tcp_sndbuf\n\r");
	}

	/* free the received pbuf */
	pbuf_free(p);

	return ERR_OK;
}

err_t connection_established()
{
	connected = 1;
	return ERR_OK;
}

uint8_t client_connected()
{
	return connected;
}

uint8_t client_connection_lost(struct conn_info* conn)
{
	return (conn->pcb->state != ESTABLISHED);
}

int client_abort(struct conn_info* conn)
{
	/* disconnect from conn */
	connected = 0;
	tcp_abort(conn->pcb);
	return 0;
}

int client_connect(struct conn_info* conn)
{
	/* reset globals */
	conn->pcb = tcp_new();
	if (!conn->pcb) {
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* connect to conn */
	unsigned int fails = 0;
	err_t err = tcp_connect(conn->pcb, &conn->ipaddr, conn->port, NULL);
	while (err != ERR_OK) {
		xil_printf("Unable to connect to conn: err = %d\n\r", err);
		if (fails > 5) {
			return -2;
		}
		err = tcp_connect(conn->pcb, &conn->ipaddr, conn->port, connection_established);
	}

	/* we do not need any arguments to callback functions */
	tcp_arg(conn->pcb, NULL);

	/* set the receive callback for this connection */
	tcp_recv(conn->pcb, recv_callback);

	/* just use an integer number indicating the connection id as the
		   callback argument */
	static int connection = 1;
	tcp_arg(conn->pcb, (void*)(UINTPTR)connection);
	connection++;

	return 0;
}

