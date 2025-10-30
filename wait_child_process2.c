#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

  int main(){
     int pid = fork();
     if(pid > 0){
        int status;
        wait(&status);
        printf("child process has finished with %d\n",WEXITSTATUS(status));
     }
     else if(pid == 0){
        sleep(3);
        exit(42);
     }
  }