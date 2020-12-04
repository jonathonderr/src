#include <stdio.h>

char **environ;

int main(int argc, char* argv[]) {
	for(int i=0; i < 2; i++){
		printf("Env %i: %s\n", i, environ[i]);
		}
		
	char *testEnviron[0];
			
	pid_t pid;
	char *cmd[] = {"ls"};
	int status;
	status = posix_spawn(&pid, "/home/kyle/src/hello_world", NULL, NULL, NULL, cmd, environ);
	if(status == 0){
		printf("Child pid: %i\n", status);
		if(waitpid(pid, &status, 0) != -1){
			printf("Child exited with status %i\n", status);
		} else {
			perror("waitpid");
			}
	} else {
		printf("posix_spawn %s\n", strerror(status));
		}
	return 0;
}
