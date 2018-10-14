# Makefile for the socket programming example
#

server_objects = ServerSocket.o Socket.o server.o
simple_client_objects = ClientSocket.o Socket.o simple_client.o


all : server client

server: $(server_objects)
	g++ -o server $(server_objects)


client: $(client_objects)
	g++ -o client $(client_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
server: server.cpp
client: client.cpp


clean:
	rm -f *.o server client
