/*
============================================================================
Name : 19.c
Author : NIKHIL NM 
Description : Write a program to remove the message queue. 
Date: 11th October, 2023
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msqid;

    // Create or get the message queue using a unique key
    key = ftok(".", 'a');
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue using IPC_RMID
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
