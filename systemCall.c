#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

void run_cmd(char *cmd){
      int status;
      status = system(cmd);
      
      if(status==-1){	      
     	 printf("system error: %s\n", strerror(status));
      }
}

int main(int argc, char* argv[]){
        run_cmd("pwd");
        return 0;
}
