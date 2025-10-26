#include<stdio.h>
#include<unistd.h>
//buffer olmadığı bir senaryoda işlemleri yaparsak 
  
int main(){
    for(int i=0; i<=2;i++){
        if(i<2){
            fork();
        }
        printf("X\n"); 
    }


    return 0;
}