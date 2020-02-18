//Sam Stecker 12/10/19
//CS252

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <signal.h>


void parseArgs(char*, char**, int, int*);
int checkRedirectInput(char**, int);
int checkRedirectOutput(char**, int);
void deleteIndex(char**, int);


//buffer is the input string of characters
//args is the output array of arguments.  It has already been created with argsSize slots.
//nargs as the number filled in that is passed back
	void parseArgs(char* buffer, char** args, int argsSize, int *nargs) {
		char *bufArgs[argsSize];
		char **cp;
		char *wbuf;
		int i, j;

		wbuf = buffer;
		bufArgs[0] = buffer;
		args[0] = buffer;

		for (cp=bufArgs; (*cp=strsep(&wbuf, " \n\t")) != NULL;) {

			if ((*cp != '\0') && (++cp >= &bufArgs[argsSize])) {
				break;
			}
		}	

		for (j=i=0; bufArgs[i] != NULL; i++) {

			if (strlen(bufArgs[i]) > 0 ) {
				args[j++] = bufArgs[i];
			}
				
		}

		//Add the NULL as the end argument because we need that for later
		*nargs = j;
		args[j] = NULL;

	}	

 void deleteIndex(char** args, int index) {

	int i = index;

	while(args[i + 1] != NULL) {

		//args[i] += args[i] + 1
		args[i] = args[i + 1];
		i++;
	}

	args[i] = NULL;
 }

 int checkRedirectOutput(char** args, int nargs) {//function used to check if user is redirecting to output

	int i = 0;
	while (i < nargs) {

		if (strcmp(args[i], ">") == 0) {
			return i;
		}
		i++;

	}

	return -1;

 } 


 int checkRedirectInput(char** args, int nargs) {//function used to check if user is redirecting from an input

	int i = 0;
	while (i < nargs) {

		if (strcmp(args[i], "<") == 0) {
			return i;
		}
		i++;
	}
	
	return -1;

 }




 int main() {

	int exit = 0;
	while(exit == 0) {

		printf("%s>", getcwd(0,0));	//declaration of variables		
		char buffer[40];
		fgets(buffer, 40, stdin);
		char* args[10];
		int nargs;
		parseArgs(buffer, args, 10, &nargs);
		int argIndex = 0;
		char userInput[20];
		char userOutput[20];

		if (strcmp(args[0], "exit") == 0) {//checks if the user has input exit 

			exit = 1;				
		}

 
			else if (strcmp(args[0], "cd") == 0) {//checks to see if the directory is valid or not
			
				int dir = chdir(args[1]);

				if (dir != 0) {
				
					printf("Directory cannot be found\n");
				}

			}

		 else {
			int pid = fork();//assign the pid of the forked process
			if (pid == -1) {
				printf("Invalid fork");//shouldn't happen but incase it does
				
				
			} 


			else if (pid == 0) { //child process
			
				int inputRedirect = checkRedirectInput(args, nargs);

					if (inputRedirect != -1) {//

						strcpy(userInput, args[inputRedirect + 1]);

						deleteIndex(args, inputRedirect + 1);

						deleteIndex(args, inputRedirect);

						//redirecting the stream
						freopen(userInput, "r", stdin);
					}
					
				int outputRedirect = checkRedirectOutput(args, nargs);
				
					if (outputRedirect != -1) {
					
						strcpy(userOutput, args[outputRedirect + 1]);
						deleteIndex(args, outputRedirect + 1);
						deleteIndex(args, outputRedirect);
				
						//redirection of stream	
						freopen(userOutput, "w", stdout);
				}
				
					//executes the command
					execvp(args[0], args);

			}
 
			else { //parent process
				int infoParse;
				waitpid(pid, &infoParse, 0);	
			}		
		}

	}			

 }
