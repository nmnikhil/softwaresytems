/*
============================================================================
Name : 10.c
Author : NIKHIL NM 
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes. 
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the data
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main (){
int fd;
int i;
char line1[20] = "what is up";
char line2[20] = "nothing much";
fd = open ("filedwr.txt",O_RDWR | O_CREAT);
write(fd,line1,10);
i=lseek(fd,10,SEEK_CUR);
write (fd,line2,10);
printf("return value of lseek() is %d\n",i);
close(fd);
return 0;
}
