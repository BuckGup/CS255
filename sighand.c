//Sam Strecker 11/25/19
#include <stdio.h>
#include <signal.h>
//ps reports a snapshot of the current processes unlike top which shows the live processes 
//ps -ejH prints a process tree which is useful to see the hierarchy of a process to see exactly who is running what 
//ps -U root -u root u allows us to see every process running as root which can be benifical from a security standpoint

int signalHandler(int incomingSignal);

	void main(){

		signal(SIGINT, signalHandler);
		while(1){
		} 		
	}


	int signalHandler(int incomingSignal){

		printf("Sig handler called with %d", incomingSignal);
		exit(1);
	}



