/*
============================================================================
Name : 9.c
Author : NIKHIL NM 
Description : Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
Date : 28 August 2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main(){
struct stat s;
stat("employee.txt",&s);
printf("srcfile details : \n");
printf ("inode no : %ld\n",s.st_ino);
printf("number of hardlinks : %ld\n",s.st_nlink);
printf("user id : %d\n",s.st_uid);
printf ("group id : %d\n",s.st_gid);
printf("size : %ld\n",s.st_size);
printf("blocksize : %ld\n",s.st_blksize);
printf("number of blocks : %ld\n",s.st_blocks);
printf("time of last access : %ld\n",s.st_atime);
printf("time of last modification : %ld\n",s.st_mtime);
printf("time of last change : %ld\n",s.st_ctime);
return 0;
}
