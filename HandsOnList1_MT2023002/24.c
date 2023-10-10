/*
============================================================================
Name : 24.c
Author : NIKHIL NM 
Description : write a program to create an orphan process
Date : 8th September 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main () {
int c = fork();

if (c==0){
printf ("child process is running and its parent  id is %d\n",getppid());
sleep(10);
printf ("child's parent id after becoming orphan process is %d\n",getppid());
}
else {
printf("parent process is running and its process id is %d\n",getpid());

}
}
