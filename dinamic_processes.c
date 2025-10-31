#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<time.h>
int main(){
    int count_child_process;
    printf("enter a value:");
    scanf("%d",&count_child_process);
    int child_pid[count_child_process];

    for(int i=0; i<count_child_process;i++){
        int pid = fork();
        if(pid == 0){
            srand(time(NULL) ^ (getpid() << 16));
            int sleep_time = (rand() % 5) + 1;  
            int exit_code = rand() % 256; 
             printf("iam child %d my process id is %d parent is %d and i sleep %d\n",i+1,getpid(),getppid(),sleep_time);
             sleep(sleep_time);
             exit(exit_code);
        }
        else if(pid > 0){
            child_pid[i] = pid;
        }
        else{
            exit(1);
        }
    }


    for(int i =0; i<count_child_process; i++){
        int status;
        pid_t finished_pid = wait(&status);
        for(int j=0; j<count_child_process; j++){
            if(finished_pid == child_pid[j]){
                printf("%d child has teminated exit %d\n",j+1,WEXITSTATUS(status));
                break;
            }
           
        }

    }
}