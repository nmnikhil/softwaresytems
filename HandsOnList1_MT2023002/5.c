/*
============================================================================
Name : 5.c
Author : NIKHIL NM 
Description :Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd
Date : 28 August 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
char fn [32];
int count =5;
while (count){
sprintf(fn,"q%d.txt",count);
FILE *fp=fopen(fn,"w+");
count--;
}
while (1);
}
