#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
int main(){
    if(fork()){
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("child has finished succesfully with %d\n",WEXITSTATUS(status));
            }
            else{
                printf("child has crashd.\n");
        }
       
    }
    else{
        int x;
        scanf("%d",&x);
        return 20/x;
    }
}