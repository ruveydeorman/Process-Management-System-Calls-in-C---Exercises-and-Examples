#include<stdio.h>
#include<unistd.h>
    int main(){
      printf("Before fork- MyPID is %d\n",getpid());
      int returned_fork = fork();
      if(returned_fork == -1){
        printf("fork failed !");
      }
      else if(returned_fork == 0){
        printf("Child , fork() returned %d\n",returned_fork);
        printf("Child , my pid is %d\n",getpid());
        printf("Child, my parent process id is %d\n",getppid());
      }
      else{
        printf("Parent , fork() returned my child process with %d\n",returned_fork);
        printf("Parent , my  pid is %d\n",getpid());
      }
      return 0;
    }
