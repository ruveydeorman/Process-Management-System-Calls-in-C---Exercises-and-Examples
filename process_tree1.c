#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    int pid;
    int x=3;
    do{
        x--;
       
        pid=fork();
        if(pid){
            printf("X\n");
        }
         printf("Y\n");
       
    }
    while ((x==2 || pid)&& x>0);
    return 0;
}