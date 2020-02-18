//Sam Strecker 11/25/19

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

	int main(){

		char *arg1[3];
		arg1[0] = "ls";
		arg1[1] = "-l";
		arg1[2] = NULL;

		char *arg2[3];
		arg2[0] = "ps";
		arg2[1] = NULL;

		int forkID = fork();	

		if(forkID == -1){
			printf("***ERROR: child fork process failed\n");
			exit(0);
		}
		else if(forkID == 0){
		printf("Inside the loop");	
		execvp(arg1[0],arg1); 
		//execvp(arg2[0],arg2);
		printf("The child process id %d", getpid());	
		}
	
		//kill(pidParent, SIGKILL);

		return 0;	
	}













