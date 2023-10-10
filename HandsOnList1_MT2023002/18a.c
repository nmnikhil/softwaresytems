/*
============================================================================
Name : 18a.c
Author : NIKHIL NM 
Description : Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date : 28 August 2023
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main () {

struct {
 int trn_no; 
 int ticket;
}db[3];

for (int i=0;i<3;i++){
     db[i].trn_no=i+1;
    db[i].ticket =0;
}
int fd; 
fd = open("train.txt",O_RDWR);
write(fd,db,sizeof(db));
close (fd);

return 0;

}
