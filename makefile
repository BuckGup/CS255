all: server client

client: client.o
	gcc -o client client.o -std=c99
client.o: client.c
	gcc -c client.c -std=c99

server: server.o
	gcc -o server server.o -std=c99
server.o: server.c
	gcc -c server.c -std=c99

clean:
	rm *.o client server
