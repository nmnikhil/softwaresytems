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
    key_t shmKey;         // Key used to create / access Shared Memory
    int shmIdentifier;    // Identifier for the Shared Memory
    ssize_t shmSize = 20; // Size of the Shared Memory
    char *shmPointer, *rdOnlyShmPointer;

 int key, shmid;
 char *data;
 key = ftok(".", 'b');
 // Create shared memory of size 1024 bytes
 shmid = shmget(key, 1024, IPC_CREAT|0744);

data = shmat(shmid, 0, 0);
printf("Enter the text: ");
scanf("%[^\n]", data);

//displaying data from the shared memory

 shmid = shmget(key, 1024, 0);
 // Return value of shmat is pointer to start of shared memory which
 data = shmat(shmid, 0, 0);
 printf("Text from shared memory: %s\n", data);
 // This is just to check nattch value in ipcs-m output
 getchar();
    // ======================== 3 ========================
    printf("Detaching pointer to shared memory!\n");
    shmdt(shmid);       // Dettach pointer to Shared Memory
   // shmdt(rdOnlyShmPointer); // Dettach pointer to Shared Memory
    // ===================================================

    // ======================== 4 ========================
    printf("Press enter to delete the shared memory!\n");
    getchar();

    // Delete Shared Memory
    shmctl(shmid, IPC_RMID, NULL);
    // ===================================================
}
