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

#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
int main(){
    int k, shmid;
    char  *data;

    k = ftok(".",'a');
    shmid = shmget(k,1024,IPC_CREAT | 0744);
    data = shmat(shmid,0,SHM_RDONLY);
    printf("data: %s\n",data);
    
    printf("Enter data to overwrite: ");
    scanf("%[^\n]",data);
    if(shmdt(data)==-1){
        perror("shmdt");
    }
    return 0;
}
