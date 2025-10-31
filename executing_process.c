#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(){
    int pid =fork();
    if (pid == 0 ){
        execlp("ls","ls","-l",NULL);
        perror("cannot run 'ls' ");
    }
    else if(pid > 0){
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("child has finished %d\n",WEXITSTATUS(status));
        }
    }


}