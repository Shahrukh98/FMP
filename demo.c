// #include<stdio.h>
// #include<string.h>
// #include<unistd.h>

// void main(){
//     char str[] = "strtok needs to be called several times to split a string";
// 	int init_size = strlen(str);
// 	char delim[] = " ";

// 	char *ptr = strtok(str, delim);

// 	while(ptr != NULL)
// 	{
// 		printf("'%s'\n", ptr);
// 		ptr = strtok(NULL, delim);
// 	}

// 	/* This loop will show that there are zeroes in the str after tokenizing */
// 	for (int i = 0; i < init_size; i++)
// 	{
// 		printf("%d ", str[i]); /* Convert the character to integer, in this case
// 							   the character's ASCII equivalent */
// 	}
// 	printf("\n");

// }

#include <stdio.h> #include <stdlib.h> #include <errno.h> #include <string.h> #include "shell.h" int main(int argc, char **argv) { char *cmd; do { print_prompt1(); cmd = read_cmd(); if(!cmd) { exit(EXIT_SUCCESS); } if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0) { free(cmd); continue; } if(strcmp(cmd, "exit\n") == 0) { free(cmd); break; } printf("%s\n", cmd); free(cmd); } while(1); exit(EXIT_SUCCESS); }
