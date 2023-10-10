/*
============================================================================
Name : 27.c
Author : NIKHIL NM 
27. Write a program to execute ls -Rl by the following system calls
 a. execl
 b. execlp
 c. execle
Date : 8th September 2023
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
   printf("Enter 1 for execl\n");
   printf("Enter 2 for execlp\n");
  printf("Enter 3 for execle\n");
  printf("Enter 4 for execv\n");
  printf("Enter 5 for execvp\n");
  int num;
  scanf("%d",&num);
  switch(num){
       case 1:
         execl("/usr/bin/ls","/usr/bin/ls","-Rl",NULL);
         break;
       case 2:
         execlp("ls","ls","-Rl",NULL);
         break;
       case 3:
        char* envp[] = {"/usr/local/lib",0};
        execle("/usr/bin/ls","/usr/bin/ls","-Rl",NULL,envp);
       case 4:
         char *argt[]={"/usr/bin/ls","-Rl",NULL};
         execv("/usr/bin/ls",argt);
         break;
       case 5:
          char *args[]={"ls","-Rl",NULL};
          execvp("ls",args);
          break;
        }
      
}
