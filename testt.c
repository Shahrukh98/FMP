#include<stdio.h>
#include<unistd.h>

int main(){

    if(fork()==0){
        printf("Abdc");
    }
    else{
        printf("asfsn");

        fork();
    }
    return 0;
}