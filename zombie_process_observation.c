#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(){
    int pid = fork();
    if(pid == 0){
        printf("iam child process my pid is %d\n",getpid());
        exit(42);
    
    }
    else if(pid > 0){
       
        printf("iam parent process ,i sleep 30 second\n");
        for(int i = 30;i > 0; i--){
            printf("%d seconds left\n",i);
            sleep(1);
        }
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("child process is exited with %d and child pid is %d\n",WEXITSTATUS(status),pid);
        }
    }
    else{
        exit(1);
    }



}