/*
============================================================================
Name : 16b.c
Author : NIKHIL NM 
Description : Write a program to perform mandatory locking.
b.Implement read lock
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
struct  flock lock;
int fd;
fd = open ("1.txt",O_RDWR);
lock.l_type=F_RDLCK;
lock.l_whence = SEEK_SET;
lock.l_start = 0;
lock.l_len = 0;
lock.l_pid = getpid();
printf("before entering the critical section\n");
fcntl (fd,F_SETLKW,&lock);
printf("inside the critical section\n");
printf("press enter to unlock\n");
getchar();

lock.l_type =F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("unlocked\n");

return 0 ;

}
