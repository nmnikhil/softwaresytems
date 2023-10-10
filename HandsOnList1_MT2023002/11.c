/*
============================================================================
Name : 11.c
Author : NIKHIL NM 
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
int fd2,fd3;
int fd = open("dup.txt",O_RDWR | O_CREAT );
char line [30] = "checking for file discriptor";
int fd1 = dup(fd);
printf("the values of file descriptors are : fd1 = %d, fd2= %d\n",fd,fd1);
write (fd1,line,30);
//write (fd,line,30);

dup2(fd1,fd);
printf("the values of file descriptors are : fd1 = %d, fd2=%d\n",fd1,fd);

fd2 = fcntl (fd,F_DUPFD,0);
write (fd2,line,30);
printf("the values of file descriptors after using the fcntl function are : fd1 = %d, fd2=%d\n",fd,fd2);
close (fd);
close (fd1);
close (fd2);
return 0; 
}
