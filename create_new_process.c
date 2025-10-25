#include<stdio.h>
#include<unistd.h>
    int main(){
     int pid = fork();
     if(pid == -1){
         perror("fork error");
         return -1;
     }
     else if(pid == 0){
        printf("i am the child process with PID:%d, PPID:%d\n",getpid(),getppid());
     }
     else{
        printf("i am the parent process with PID:%d, PPID:%d\n",getpid(),getppid());
     }


        return 0;
    }
