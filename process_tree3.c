#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(){
 int pid1 = fork();
 if(pid1 == 0){
     int pid2 = fork();
     if(pid2==0){
        printf("iam grandchild my pid %d and my parent pid is %d\n",getpid(),getppid());
        sleep(5);
        exit(0);
     }
     else if(pid2 > 0){
        wait(NULL);
        printf("iam child  my pid is %d and my parent pid is %d\n",getpid(),getppid());
        
     }
     exit(0);
 }
 else if(pid1 > 0){
    wait(NULL);
    printf("iam parent my pid is %d and my parent pid is %d\n",getpid(),getppid());
 }




}