/*
============================================================================
Name : 3.c
Author : NIKHIL NM 
Description :Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date : 28 August 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main (){
int p = creat("new.txt",O_RDWR);
printf("%d",p);
return 0;
}
