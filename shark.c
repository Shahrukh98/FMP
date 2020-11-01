#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define MAX_LINE 80 /* The maximum command length */

int main(void){
    char * args[MAX_LINE/2 +1]; /*command line arguements*/
    char straa[MAX_LINE];
    char * exit_command = "exit\n";
    int lastIndex;
    int parentWait;
    int argc,argcc;
    char * history="";
    int should_run=1;

    
    while(should_run){
        parentWait=0;
        printf("shark> ");
        fgets(straa,MAX_LINE,stdin);
        if(straa[0]=='!' && straa[1]=='!'){
            printf("Here");            if(history!=""){;
                strcpy(history,straa);
            }
            else{
                printf("Ja bsdk");
                continue;
            }
        }
        printf("\n %d \n",strlen(history));
        
        char* p = strtok(straa," ");
        while(p!=NULL){
                args[argc] = p;
                argc++;
                p = strtok(NULL ," ");
        }
        argcc=argc-1;
        args[argc]=NULL;
        argc = 0;
        lastIndex=strlen(args[argcc]); 
        args[argcc][lastIndex-1]=NULL;
        
        printf("Length of input %d",strlen(straa));
        // lastIndex=strlen(straa); 
        // history[lastIndex]=NULL;

        // printf("%c",args[argcc][lastIndex-1]);
        // args[argcc][strlen(args[argcc])-1]='\o';
        if(!strcmp(args[argcc],"&")){
            printf("BoobOn");
            args[argcc]=NULL;
            parentWait=1;
        }
        if(!strcmp(args[0],exit_command)){
            break;
        }

        if(fork()==0){
            execvp(args[0],args);
            fflush(stdout);
        }
        else{
            if(parentWait)
            {
                printf("Boobon");
            }
            else{
                            wait(NULL);
            }            
            printf("GO EAT A DICK!");
        }



    }
    return 0;
}