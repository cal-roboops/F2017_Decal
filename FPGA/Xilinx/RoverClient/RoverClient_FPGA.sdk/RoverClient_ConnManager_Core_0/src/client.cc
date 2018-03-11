/*
 * Client.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Mitchell Oleson
 */

#include "client.h"
#include "xil_printf.h"

Client::Client(std::vector<u32_t> ip, unsigned port) {
	c_info.port = port;
	if (ip.size() != 4) c_info.ipaddr.addr = IPADDR_NONE;
	else IP4_ADDR(&c_info.ipaddr, ip[0], ip[1], ip[2], ip[3]);
}

Client::~Client () {
	this->disconnect();
}

err_t Client::connect() {
	/* Re-initialize data */
	c_info.pcb = tcp_new();
	if (!c_info.pcb) {
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* Connect to the IP */
	err_t err = tcp_connect(c_info.pcb, &c_info.ipaddr, c_info.port, NULL);
	while (err != ERR_OK) {
		xil_printf("Unable to connect to conn: err = %d\n\r", err);
		return err;
	}

	/* No arguments to callback functions */
	tcp_arg(c_info.pcb, NULL);

	/* Set the receive callback for this connection */
	tcp_recv(c_info.pcb, Client::recv_callback);

	/* just use an integer number indicating the connection id as the
			   callback argument */
	static int connection = 1;
	tcp_arg(c_info.pcb, (void*)(UINTPTR)connection);
	connection++;

	return ERR_OK;
}

err_t Client::disconnect() {
	if (c_info.pcb) tcp_abort(c_info.pcb);
	return ERR_OK;
}

err_t Client::connected() {
	xil_printf("State: %d\r\n", c_info.pcb->state);
	return (c_info.pcb->state != CLOSED);
}

int Client::transfer_data() {
	return 0;
}

void Client::print_state() {
	xil_printf("State: %d\r\n", c_info.pcb->state);
}

err_t Client::recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p) {
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		return ERR_CONN;
	}

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->len);

	/* Echo back the pay load */
	if (tcp_sndbuf(tpcb) > p->len) err = tcp_write(tpcb, p->payload, p->len, 1);
	else xil_printf("no space in tcp_sndbuf\n\r");

	/* free the received pbuf */
	pbuf_free(p);

	return ERR_OK;
}
