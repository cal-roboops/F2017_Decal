/*
 * client.h
 *
 *  Created on: Jan 26, 2018
 *      Author: PC
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include "lwip/err.h"
#include "lwip/tcp.h"

struct conn_info {
	unsigned port;
	struct ip_addr ipaddr;
	struct tcp_pcb *pcb;
};

int transfer_data();

uint8_t client_connected();
uint8_t client_connection_lost(struct conn_info* conn);

int client_connect(struct conn_info* server);
int client_abort(struct conn_info* server);


#endif /* SRC_CLIENT_H_ */
