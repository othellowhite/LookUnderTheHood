#include <signal.h>

static void sig_usr(int signo) {

	printf ("handlr got somnething : ");
	if(signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if(signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else 
		printf("received sig : %d\n", signo);

	return;
}

int main(void) {
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR1");
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("can't catch SIGUSR2");

	while(1) pause();
	
	return 0;
}
