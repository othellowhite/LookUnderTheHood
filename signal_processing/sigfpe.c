#include <signal.h>

static void sig_fpe(int signo) {
	pid_t  pid;
	int status;
	pid = wait(&status);
    printf("sighndlr> Div. by 0 Err !!!\n");
    sleep(1);
	//exit(0);
}

int main(void) {
	pid_t pid;
	int i;
	signal(SIGFPE, sig_fpe);
	
    i = i/0;
	
	
	return 0;
}
