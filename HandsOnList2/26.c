/*
============================================================================
Name : 26.c
Author : NIKHIL NM 
Description : Write a program to send messages to the message queue.
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
    } myq;

    key_t key; // Declare key
    int mqid;   // Declare mqid
    size_t size; // Declare size

    key = ftok(".", 'a');

    mqid = msgget(key, 0666 | IPC_CREAT); // Create or get a message queue

    if (mqid == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Enter message type: ");
    scanf("%ld", &myq.m_type);

    printf("Enter message text: ");
    scanf(" %[^\n]", myq.message); // Note the space before %[^\n] to consume leading whitespace

    size = strlen(myq.message);

    // size + 1 to accommodate the terminating null character
    if (msgsnd(mqid, &myq, size + 1, 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
      msgsnd(id,&myq,size,0);
    printf("Message sent successfully to message queue with key %d\n", mqid);

    return 0;

    return 0;
}

