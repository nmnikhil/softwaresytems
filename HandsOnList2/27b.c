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
#include <string.h> 
int main() {
 struct msg {
 long int m_type;
 char message[80];
 } myq[2];
key_t key;
int mqid;
size_t size;
 key = ftok(".", 'a');
 mqid = msgget(key, 0);
 printf("Enter message type: ");
 scanf(" %ld", &myq[0].m_type);
     // Receive a message with no flag (blocking)
    printf("Receiving a message with no flag (blocking)...\n");
    msgrcv(mqid, &myq, sizeof(myq[0].message), myq[0].m_type, 0);
    printf("Received message with type %ld: %s\n", myq[0].m_type, myq[0].message);
 printf("Enter message type: ");
 scanf(" %ld", &myq[1].m_type);
int ret1 = msgrcv(mqid, &myq[1], sizeof(myq[1].message), myq[1].m_type, IPC_NOWAIT | MSG_NOERROR);

 if (ret1 ==-1)
 exit(-1);
  printf("Receiving a message with IPC_NOWAIT flag (non-blocking)...\n");
 printf("Message type: %ld\n Message: %s\n", (myq+1)->m_type, myq[1].message);
 }
