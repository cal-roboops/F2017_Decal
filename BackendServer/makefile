lin: client_lin

win: client_win

server:
	g++ server.cpp -o server -lpthread

client_lin:
	g++ client.cpp -o client

client_win:
	g++ client.cpp -o client -Wall -Wno-long-long -lws2_32 -lwsock32

clean:
	rm -f server client