#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

static void sig_handlr(int signo) {

	printf ("sighandlr> ");

	if(signo == SIGUSR1)
		printf("Saving Batt\n");

	else if(signo == SIGUSR2)
		printf("normal mode\n");

	else if(signo == SIGINT)
		printf("received SIGINT\n");

	else if(signo == SIGQUIT)
        printf("received SIGQUIT\n");
    
    else if(signo == SIGSTOP) 
        printf("received SIGSTOP\n");
    
    else if(signo == SIGKILL)
        printf("received SIGKILL\n");

	else 
		printf("received sig : %d\n", signo);

	return;
}

int main(void) {

	pid_t process_id = 0;
	pid_t sid = 0;

// Create child process
	process_id = fork();

// Indication of fork() failure
	if (process_id < 0)
	{
		printf("fork failed!\n");
		exit(1); // Return failure in exit status
	}

// PARENT PROCESS. Need to kill it.
	if (process_id > 0)
	{
		printf("process id of child process : %d \n", process_id);
		exit(0); // return success in exit status
	}

// set a siganl handler	
	if(signal(SIGUSR1, sig_handlr) == SIG_ERR)
		printf("can't catch SIGUSR1\n");

	if(signal(SIGUSR2, sig_handlr) == SIG_ERR)
		printf("can't catch SIGUSR2\n");

	if(signal(SIGINT, sig_handlr) == SIG_ERR)
		printf("can't catch SIGINT\n");

	if(signal(SIGQUIT, sig_handlr) == SIG_ERR)
        printf("can't catch SIGQUIT\n");
    
    if(signal(SIGSTOP, sig_handlr) == SIG_ERR)
        printf("can't catch SIGSTOP\n");
    
    if(signal(SIGKILL, sig_handlr) == SIG_ERR)
        printf("can't catch SIGKILL\n");

	while(1) pause();
	
	return 0;
}
