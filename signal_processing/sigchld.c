#include <signal.h>

static void sig_child(int signo) {
	pid_t  pid;
	int status;
	pid = wait(&status);
	printf("child of %d finished\n", pid);
}

int main(void) {
	pid_t pid;
	int i;
	signal(SIGCHLD, sig_child);
	pid = fork();

	printf("process id : %d \n", pid);

	if(pid==0) {
		sleep(1);
		printf("pid %d now exit(1) : \n", pid);
		exit(0);

	}
	else {while(1){
		sleep(2);
		printf("pid %d now in infinite loop . \n", pid);
	}}
}
