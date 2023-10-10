/*
============================================================================
Name : 13.c
Author : NIKHIL NM 
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select)
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
fd_set rd;
struct timeval tv;

FD_ZERO(&rd);
FD_SET(0,&rd);
tv.tv_sec =10;
printf("waiting for input\n");
int retval = select (1,&rd,NULL,NULL,&tv);


if (retval)
{

printf("the value was entered within 10 seconds:\n");

}
else {
printf("data was not  entered within 10 secconds\n");
}
return 0;
}
