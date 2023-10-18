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
char buff[80];
fd_set rfds;
 struct timeval tv;
 tv.tv_sec = 15;
int  fd = open("nick", O_RDONLY);
 FD_ZERO(&rfds);
 FD_SET(fd, &rfds);
if (!select(fd + 1, &rfds, NULL, NULL, &tv))
 printf("No data is available for reading yet\n");
 else {
 printf("Data is available now\n");
 read(fd, buff, sizeof(buff));
 printf("Data from FIFO: %s\n", buff);
 }
}
