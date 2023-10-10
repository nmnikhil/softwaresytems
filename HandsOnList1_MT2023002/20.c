/*
============================================================================
Name : 20.c
Author : NIKHIL NM 
Description :Find out the priority of your running program. Modify the priority with nice command
Date : 8th September 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>

int main(){
id_t pid;
pid =getpid();
//ret =getpriority(which,pid);
printf("the priority of the process is : %d\n",nice(0));
printf("%d \n",getpid());
printf("changing the priority of the process....\n");

int priority =-14;
getchar();
//ret = setpriority(which,pid,priority);
printf("the new priority of the process is : %d\n",nice(priority));
while(1);
return 0;
}
