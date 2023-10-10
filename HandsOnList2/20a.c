/*
============================================================================
Name : 19.c
Author : NIKHIL NM 
Description : Create a FIFO file by
		a. mknod command
		b. mkfifo command
		c. use strace command to find out, which command (mknod or mkfifo) is better.
		d. mknod system call
		e. mkfifo library function

Date: 9th October, 2023
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main () {
char buff [90];
int fd = open ("nick",O_WRONLY);
 printf("Enter the text:");
 scanf(" %[^\n]", buff);
 write(fd, buff, sizeof(buff));
}
