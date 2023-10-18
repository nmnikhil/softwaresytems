/*
============================================================================
Name : 20.c
Author : NIKHIL NM 
Description :  Write two programs so that both can communicate by FIFO -Use one way communication.
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

int main() {
char buff[90];
int fd = open ("nick",O_RDONLY);
 read(fd, buff, sizeof(buff));
 printf("The text from FIFO file: %s\n", buff);
}
