#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        execl("/bin/ps","ps","aux",NULL);

    }
    else if(pid > 0){
        int status;
        wait(&status);
        if(WIFEXITED(status)){
          printf("child process has exited with %d\n",WEXITSTATUS(status));
        }
    }
    else{
        exit(1);
    }
}