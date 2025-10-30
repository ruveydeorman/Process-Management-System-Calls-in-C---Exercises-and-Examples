#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
  int main(){
    int i;
    int sleep_time[]={1,2,3};
    int exit_value[]={10,20,30};
    int child_pid[3];
    for(i =0; i<3; i++){
        int pid = fork();
        if(pid == 0){
            sleep(sleep_time[i]);
            exit(sleep_time[i]);
        }
        else if(pid > 0){
            child_pid[i]= pid;
         }
        else{
            exit(1);
        }
       
    }
    for(i =0; i<3; i++){
        int status;
        pid_t finished_pid = wait(&status);

        for(int j=0; j<3; j++){
            if(finished_pid == child_pid[j] ){
                printf(" %d . child has terminated with exit %d\n",j + 1 ,exit_value[j]);
                break;
            }
        }
    }


  return 0;
  }