/*
============================================================================
Name : 12.c
Author : NIKHIL NM 
Description :Write a program to find out the opening mode of a file. Use fcntl.
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main () {
int mode;
int fd1 = open("dup.txt",O_RDWR);
mode = fcntl(fd1,F_GETFL);
if (mode & O_RDONLY)
printf("File is open for only reading\n");
if (mode & O_RDWR)
printf("file is open for reading and writing\n");
if (mode & O_WRONLY)
printf("file is open for writing only\n");
close(fd1);
}
