/*
============================================================================
Name : 17.c
Author : NIKHIL NM 
Description : Write a program to simulate online ticket reservation. Implement write lock 
Write a program to open a file, store a ticket number and exit. Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file.
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
int fd;int tick_num;
fd =open("record.txt",O_RDWR|O_CREAT);
tick_num=1;
write(fd,&tick_num,sizeof(tick_num));
close(fd);
return 0 ;
}
