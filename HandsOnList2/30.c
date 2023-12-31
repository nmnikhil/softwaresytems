/*
============================================================================
Name : 30.c
Author : NIKHIL NM 
Description : Write a program to create a shared memory. 
a. write some data to the shared memory 
b. attach with O_RDONLY and check whether you are able to overwrite. 
c. detach the shared memory 
d. remove the shared memory 

Date: 11th October, 2023
============================================================================
*/
#include <sys/types.h> // Import for `ftok`, `shmget`, `shmat`
#include <sys/ipc.h>   // Import for `ftok`, `shmget`
#include <sys/shm.h>   // Import for `shmget`, `shmat`
#include <unistd.h>    // Import for `_exit`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    int k, shmid;
    char  *data;

    k = ftok(".",'a');
    shmid = shmget(k,1024,IPC_CREAT | 0744);
    data = shmat(shmid,0,0);
    printf("Enter text: ");
    scanf("%[^\n]",data);
}
