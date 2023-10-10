/*
============================================================================
Name : 4.c
Author : NIKHIL NM 
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date : 28 August 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
int fp=open("new1.txt",O_CREAT|O_RDWR|O_EXCL);
printf ("%d",fp);
if (fp==-1)
	printf("file already exists");
return 0;
}

