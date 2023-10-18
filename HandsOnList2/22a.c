/*
============================================================================
Name : 22.c
Author : NIKHIL NM 
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
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
