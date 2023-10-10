/*
============================================================================
Name : 15.c
Author : NIKHIL NM 
Description :Write a program to display the environmental variable of the user (use environ).
Date : 28 August 2023
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

extern char **environ;
int main (){
for (int i=0;environ[i]!=NULL;i++){
 	printf("%s\n",environ[i]);
}
return 0;
}
