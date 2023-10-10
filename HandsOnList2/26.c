
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main() {
 struct msg {
 long int m_type;
 char message[80];
 } myq;
 key = ftok(".", 'a');
mqid = msgget(key, 0);
 printf("Enter message type: ");
 scanf("%ld", &myq.m_type);
 printf("Enter message text:");
 scanf("%[^\n]", myq.message);
 size = strlen(myq.message);
 // size + 1 to accommodate terminating character
 msgsnd(mqid, &myq, size + 1, 0);


}
