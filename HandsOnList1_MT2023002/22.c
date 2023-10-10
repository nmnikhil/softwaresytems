/*
============================================================================
Name : 22.c
Author : NIKHIL NM 
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file. 
Date : 8th September 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main () {
int fd = open("sample.txt",O_RDWR|O_CREAT);
int c=fork();
if (!c){
char buf[20] = "parent wrote";
printf("parent is writing onto the file \n");
write (fd,buf,sizeof(buf));
}
else{
printf("child is writing onto the file \n");
char buf1[20]="child wrote";
write (fd,buf1,sizeof(buf1));}
close(fd);
return 0;
}
