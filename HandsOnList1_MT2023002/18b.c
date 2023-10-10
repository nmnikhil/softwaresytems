/*
============================================================================
Name : 18b.c
Author : NIKHIL NM 
Description : Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
struct{
 int trn_no;
 int ticket;
}db;
int fd, input;
fd = open("record.txt", O_RDWR);
printf("Select train number: 1, 2, 3\n");
scanf("%d", &input);
struct flock lock;
lock.l_type = F_WRLCK;
lock.l_whence= SEEK_SET;
lock.l_start = (input-1)*sizeof(db);
lock.l_len = sizeof(db);
lock.l_pid = getpid();
lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
read(fd, &db, sizeof(db));
printf("Before entering critical section\n");
fcntl(fd, F_SETLKW, &lock);
printf("Current ticket count: %d\n", db.ticket);
db.ticket++;
lseek(fd, -1 * sizeof(db), SEEK_CUR);
write(fd, &db, sizeof(db));
printf("To book ticket, press enter\n");
getchar();
getchar();
lock.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &lock);
printf("Ticket booked with number %d\n", db.ticket);
return 0;
}
