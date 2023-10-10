/*
============================================================================
Name : 6.c
Author : NIKHIL NM 
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main (){
int i;
int count =10;
char buf[100];
i=read(0,buf,sizeof(buf));
printf("the value taken from stdin is:\n");

write (1,buf,sizeof(buf));

return 0;

}
