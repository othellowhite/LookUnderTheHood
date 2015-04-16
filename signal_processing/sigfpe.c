#include <signal.h>

static void sig_fpe(int signo) {
	pid_t  pid;
	int status;
	pid = wait(&status);
	printf("Div. by 0 Err !!!\n");
	//exit(0);
}

int main(void) {
	pid_t pid;
	int i;
	signal(SIGFPE, sig_fpe);
	
	while(1){
		i = i/0;
		sleep(1);
	}
	
	return 0;
}
