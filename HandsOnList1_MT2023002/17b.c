/*
============================================================================
Name : 17b.c
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
int main (){
struct {
int tick_no;
}db;
struct  flock lock;
int fd;
fd = open ("record.txt",O_RDWR);
read(fd,&db,sizeof(db));
lock.l_type=F_WRLCK;
lock.l_whence = SEEK_SET;
lock.l_start = 0;
lock.l_len = 0;
lock.l_pid = getpid();
printf("before entering the critical section\n");
fcntl (fd,F_SETLKW,&lock);
printf("current ticket number: %d\n",db.tick_no);
db.tick_no++;
lseek(fd,0L,SEEK_SET);
printf("inside the critical section\n");
printf("press enter to unlock\n");
write(fd,&db,sizeof(db));
getchar();
lock.l_type =F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("finsihed\n");
return 0 ;
}
