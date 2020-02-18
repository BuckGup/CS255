all: head node

node: node.o
	gcc -o node node.o -std=c99
node.o: node.c
	gcc -c node.c -std=c99

head: head.o
	gcc -o head head.o -std=c99
head.o: head.c
	gcc -c head.c -std=c99

clean:
	rm *.o node head
