#include <unistd.h>
#include <netinet/in.h>
#include <list>
#include <json/json.hpp>

using namespace std;
using json = nlohmann::json;

const long roverIP = 167772352; //actual rover IP
//const long roverIP = 16777343; //for testing purposes
const int MAX_SIZE_BACKLOG_QUEUE = 5;
const int bufSize = 1024;
const int EMERGENCY = -2;
const int SERVER_COMMAND = -3;

int roverCommandSocket;
int roverEmergencySocket;
pthread_mutex_t roverCommandLock;
pthread_mutex_t roverEmergencyLock;
list<struct Thread*> clientThreads;

struct Thread {
	int socket_desc;
	pthread_t* pthread;
	long ip;
	int port;
};

struct Command {
	int client_socket;
	bool finished;
	json* j;
};

void terminate_thread(struct Thread*);

void *handle_input(void*);

void *execute_rover_command(void*);

void create_thread(int, long, int);

int main() {
	int client;
	int clientListener;
	int connectAttempts;
	int clientPort = 8088;
	struct sockaddr_in server_addr, client_addr;
	int size = sizeof(struct sockaddr_in);

	pthread_mutex_init(&roverCommandLock, NULL);
	pthread_mutex_init(&roverEmergencyLock, NULL);

	clientListener = socket(AF_INET, SOCK_STREAM, 0);

	if (clientListener < 0) {
		cout << "ERROR: failed to create socket for client communication" << endl;
		exit(1);
	} 

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(clientPort);
	server_addr.sin_addr.s_addr = INADDR_ANY; // will be replaced by IP of communication receiver on rover

	if (bind(clientListener, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		cout << "ERROR: failed to bind socket for client communication" << endl;
		exit(1);
	} 

	listen(clientListener, MAX_SIZE_BACKLOG_QUEUE);
	cout << "Ready to receive client connecions...\n" << endl;

	while (true) {
		client = accept(clientListener, (struct sockaddr*) &client_addr, (socklen_t*) &size);

		if (client < 0) {
			cout << "ERROR: failed to connect to client" << endl;
		} else if (client_addr.sin_addr.s_addr == roverIP) {
			connectAttempts = 3;
			roverCommandSocket = client;

			cout << "Successfully established command/response connection to ROVER." << endl;
			cout << "Waiting to establish emergency connection to ROVER..." << endl;

			while (connectAttempts > 0) {
				client = accept(clientListener, (struct sockaddr*) &client_addr, (socklen_t*) &size);

				if (client < 0) {
					cout << "ERROR: failed to establish emergency connection to ROVER" << endl;
					cout << "Waiting for re-attempt to establish emergency connection to ROVER..." << endl;
					connectAttempts -= 1;
				} else if (client_addr.sin_addr.s_addr != roverIP) {
					cout << "ERROR: only ROVER may attempt to connect at this time" << endl;
					close(client);
				} else {
					cout << "Successfully established emergency connection to ROVER." << endl;
					roverEmergencySocket = client;
					create_thread(roverEmergencySocket, client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port));
					break;
				}
			}

			if (connectAttempts == 0) {
				cout << "ERROR: failed to connect to ROVER" << endl;
				close(roverCommandSocket);
			}
		} else {
			cout << "\nSuccessfully connected to new client." << endl;
			cout << "Client IP: " << client_addr.sin_addr.s_addr << endl;
			cout << "Client port: " << ntohs(client_addr.sin_port) << "\n" << endl;

			create_thread(client, client_addr.sin_addr.s_addr, ntohs(client_addr.sin_port));
		}
	} 
}

void create_thread(int socketID, long ipAddr, int p) {
	struct Thread* t;
	pthread_t* pt; 

	t = (struct Thread*) malloc(sizeof(struct Thread));

	if (t == NULL) {
		cout << "ERROR: failed to allocate memory" << endl;
		close(socketID);
		return;
	}

	pt = (pthread_t*) malloc(sizeof(pthread_t));

	if (pt == NULL) {
		cout << "ERROR: failed to allocate memory" << endl;
		free(t);
		close(socketID);
		return;
	}

	t -> socket_desc = socketID;
	t -> pthread = pt;
	t -> ip = ipAddr;
	t -> port = p;

	pthread_create(pt, NULL, handle_input, (void*) t);

	if (ipAddr != roverIP) {
		clientThreads.push_back(t);
	}
}

void *handle_input(void* threadStruct) {
	struct Thread* t = (struct Thread*) threadStruct;
	int socketID = t -> socket_desc;
	char buffer[bufSize];
	struct Command cmd;
	pthread_t pt;
	string serialized;
	json jobj;
	json copy;

	cmd.finished = true;

	while (true) {
		if (recv(socketID, buffer, bufSize, 0) > 0) {
			if (buffer[0] == 0) {
				continue;
			}

			try {
				jobj = json::parse(buffer);
			} catch (invalid_argument ex) {
				send(t -> socket_desc, "ERROR: failed to parse command", bufSize, 0);
				continue;
			}

			if (jobj.begin().value() == EMERGENCY) {
				pthread_mutex_lock(&roverEmergencyLock);

				serialized = jobj.dump();
				send(roverEmergencySocket, serialized.c_str(), bufSize, 0);

				pthread_mutex_unlock(&roverEmergencyLock);

			} else if (jobj.begin().value() == SERVER_COMMAND) {
				//perform server command
			} else if (!cmd.finished) {
				send(t -> socket_desc, "ERROR: previous command not yet finished", bufSize, 0);
			} else {
				copy = json::parse(jobj.dump());

				cmd.client_socket = t -> socket_desc;
				cmd.finished = false;
				cmd.j = &copy;

				pthread_create(&pt, NULL, execute_rover_command, (void*) &cmd);
			}
			
			memset(buffer, 0, sizeof(buffer));
		} else {
			if (t -> ip == roverIP) {
				cout << "\nDisconnected with ROVER.\n" << endl;
				close(roverCommandSocket);
				close(roverEmergencySocket);
			} else {
				cout << "\nDisconnected with Client (IP: " << t -> ip << ", Port: " << t -> port << ").\n" << endl;
				close(socketID);
			}

			terminate_thread(t);
			return NULL;
		}
	}
}

void *execute_rover_command(void* command) {
	struct Command* cmd = (struct Command*) command;
	struct Thread* thread;
	char buffer[bufSize];
	list<struct Thread*>::const_iterator iterator;
	string serialized;
	json jobj;

	if (pthread_mutex_trylock(&roverCommandLock) == 0) {
		serialized = cmd -> j -> dump();

		send(roverCommandSocket, serialized.c_str(), bufSize, 0);
		recv(roverCommandSocket, buffer, bufSize, 0);
		
		try {
			jobj = json::parse(buffer);

			//analyze response...

			for (iterator = clientThreads.begin(); iterator != clientThreads.end(); iterator++) {
				thread = *iterator;
				serialized = jobj.dump();

				send(thread -> socket_desc, serialized.c_str(), bufSize, 0);
			}
		} catch (invalid_argument ex) {
			cout << "ERROR: failed to parse command from ROVER" << endl;
			send(cmd -> client_socket, "ERROR: failed to parse response from ROVER", bufSize, 0);
		}
		
		pthread_mutex_unlock(&roverCommandLock);
	} else {
		send(cmd -> client_socket, "ERROR: ROVER busy executing another command", bufSize, 0);
	}
	
	cmd -> finished = true;
	pthread_exit(NULL);
}

void terminate_thread(struct Thread* t) {
	list<struct Thread*>::const_iterator iterator;

	if (t -> ip != roverIP) {
		for (iterator = clientThreads.begin(); iterator != clientThreads.end(); iterator++) {
			struct Thread* thread = *iterator;

			if (thread -> ip == t -> ip && thread -> port == t -> port) {
				clientThreads.erase(iterator);
				break;
			}
		}
	}

	free(t -> pthread);
	free(t);
	pthread_exit(NULL);
}







