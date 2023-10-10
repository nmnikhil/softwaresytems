/*
============================================================================
Name : 8.c
Author : NIKHIL NM 
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define max 1024
int main (){
int fd;
char buff[max];
int reads;
fd = open ("srcfile",O_RDONLY);
if (fd==-1){
	printf("file does not exist");}
while (reads = read(fd,buff,sizeof(buff))>0);
	write(1,buff,sizeof(buff));
//if (reads== -1)
//	printf("errror");
//buff[max]='\0';
//printf("the data in file was : %s\n",buff);
	return 0;
}

