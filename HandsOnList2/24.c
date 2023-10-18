/*
============================================================================
Name : 24.c
Author : NIKHIL NM 
Description :Write a program to create a message queue and print the key and message queue id
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
int main() {
 
 int key = ftok(".", 'a');
int  msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744);
 // %0x for Hexadecimal value
printf("key=0x%0x\t msgid=%d\n", key, msgid); 

}
