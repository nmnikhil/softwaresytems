/*
============================================================================
Name : 27.c
Author : NIKHIL NM 
Description : Write a program to receive messages from the message queue.
 a. with 0 as a flag
 b. with IPC_NOWAIT as a flag
Date: 11th October, 2023
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h> // Added for strlen

int main() {
    struct msg {
        long int m_type;
        char message[80];
    } myq[2];

    key_t key; // Declare key
    int mqid;   // Declare mqid
    size_t size; // Declare size

    key = ftok(".", 'a');

    mqid = msgget(key, 0666 | IPC_CREAT); // Create or get a message queue

    if (mqid == -1) {
        perror("msgget");
        exit(1);
    }
    for (int i =0;i<2;i++){
    printf("Enter message type: ");
    scanf("%ld", &myq[i].m_type);

    printf("Enter message text: ");
    scanf(" %[^\n]", myq[i].message); // Note the space before %[^\n] to consume leading whitespace

    size = strlen(myq[i].message);

    // size + 1 to accommodate the terminating null character
    if (msgsnd(mqid, &myq[i], size + 1, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
}
    return 0;
}
