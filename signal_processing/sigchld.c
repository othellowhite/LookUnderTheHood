#include <signal.h>

static void sig_child(int signo) {
	pid_t  pid;
	int status;
	pid = wait(&status);
	printf("sighndlr> child of %d finished\n", pid);
}

int main(void) {
	pid_t pid;
	int i;
    
	signal(SIGCHLD, sig_child);
    
    printf("\nparent process id %d will do fork().\n\n", getpid());
	pid = fork();
    
	printf("process id %d on work\n", getpid());

	if(pid==0) { // child's pid value isn't valued
		sleep(1);
		printf("\nchild process id %d now exit(0) : \n\n", getpid());
		exit(0);

	}
	else {while(1){
		sleep(2);
		printf("pid %d now in infinite loop . \n", getpid());
	}}
}
