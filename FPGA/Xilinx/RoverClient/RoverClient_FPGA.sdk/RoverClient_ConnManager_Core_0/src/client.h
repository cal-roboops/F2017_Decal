/*
 * Client.h
 *
 *  Created on: Mar 10, 2018
 *      Author: PC
 */

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include "lwip/tcp.h"
#include "lwip/init.h"
#include "lwipopts.h"
#include <list>
#include <vector>
#include <utility>

struct conn_info {
	unsigned port;
	struct ip_addr ipaddr;
	struct tcp_pcb *pcb;
};

class Client
{
public:
	Client(std::vector<u32_t> ip, unsigned port);
	~Client();

	err_t connect();
	err_t disconnect();
	err_t connected();

	int transfer_data();

	void print_state();

	static err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);

private:
	struct conn_info c_info;

	bool e_stop;
	bool shutdown;

	std::list<std::pair<uint8_t, uint8_t>> recv_commands;
};

#endif /* SRC_CLIENT_H_ */
