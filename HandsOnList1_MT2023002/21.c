/*
============================================================================
Name : 21.c
Author : NIKHIL NM 
Description :Write a program, call fork and print the parent and child process id. 
Date : 8th September 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (){
int p_pid= getppid();

int c = fork();
if(c)
{
printf("the id of the parent is %d\n",p_pid);
}
else {
printf("the id of the child is %d\n",c);
}

return 0;
}
