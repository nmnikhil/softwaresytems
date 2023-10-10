/*
============================================================================
Name : 23.c
Author : NIKHIL NM 
Description :Write a program to create a Zombie state of the running program.
Date : 8th September 2023
============================================================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
int c = fork();
if (c==0){
printf("child process is running its process id is %d\n",getpid());
exit(0);
}

else {
printf("parent process is runnning and its process id is %d\n",getpid());
sleep(50);
}
return 0;
}
