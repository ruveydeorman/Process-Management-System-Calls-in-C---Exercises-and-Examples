#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
     setbuf(stdout, NULL); 
    int pid = fork();
    if(pid > 0){
        printf("parent pid %d\n",getpid());
        sleep(2);
        printf("parent exiting...\n");
        exit(0);
    }
    else if(pid == 0){
        printf("child pid :%d\n",getpid());
        printf("child parent process pid before parent exiting :%d\n",getppid());
        sleep(4);
        printf("child parent process pid after parent process exiting :%d\n",getppid());
    }
    else{
        perror("fork is not work..");
        exit(1);
    }
    return 0;
}