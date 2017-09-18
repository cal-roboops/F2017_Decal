lin: server_lin client_lin

win: server_win client_win

server_win:
	g++ server.cpp -o server.exe -Wall -Wno-long-long -lws2_32 -lwsock32

client_win:
	g++ client.cpp -o client.exe -Wall -Wno-long-long -lws2_32 -lwsock32

clean:
	rm -f server.exe client.exe