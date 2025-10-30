#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include <string.h>
int main(){
    int pid = fork();
    if(pid > 0){
      int status;
      wait(&status);
      if(WIFEXITED(status)){
         printf("Child has finished normal with %d\n",WEXITSTATUS(status));
      }
      else{
        printf("child has crashed with signal %d (%s)\n",WTERMSIG(status),strsignal(WTERMSIG(status)));
      }
    }
    else if(pid == 0){
        int x;
        printf("enter an x number for 10 / x :");
        scanf("%d",&x);
        return 10/x;
    }
    else{
        exit(1);
    }




}