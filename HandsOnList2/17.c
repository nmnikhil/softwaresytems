/*
 * ============================================================================
 Name : 17.c
 Author : NIKHIL NM 
 Description : Write a program to execute ls -l | wc.
 a. use dup
 b. use dup2
 c. use fcntl
 Date: 11th OCT, 2023.
============================================================================
*/
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 

int main(){
int fd[2];
 pipe(fd);
 if (!fork()) {
 close(1); // close STDOUT
 	close(fd[0]);
 	dup(fd[1]); // Duplicate fd[1] to lowest fd value available = 1
 	execlp("ls", "ls", "-l", (char*) NULL);
 	// execlp() will write output of "ls -l" to fd with value = 1
 						 }

 else {
	 close(0); // close STDIN
 	close(fd[1]);
 	dup(fd[0]); // Duplicate fd[0] to lowest fd value available = 0
 	execlp("wc", "wc", (char*) NULL);

 }
 
}
