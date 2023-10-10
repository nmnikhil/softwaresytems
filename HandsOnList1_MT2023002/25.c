/*
============================================================================
Name : 25.c
Author : NIKHIL NM 
Description : Write a program to create three child processes. The parent should wait for a particular child (usewaitpid system call).
Date : 8th September 2023
============================================================================
*/
#include <unistd.h>   
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
    pid_t completedC, childA, childB, childC;
    if ((childA = fork()) == 0)
    {
        printf("Child A is sleeping\n");
        sleep(5);
        printf("Child A is awake\n");
        exit(0);
    }
    else
    {
        if ((childB = fork()) == 0)
        {
            printf("Child B is sleeping\n");
            sleep(10);
            printf("Child B is awake\n");
            exit(0);
        }
        else
        {
            if ((childC = fork()) == 0)
            {
                printf("Child C is sleeping\n");
                sleep(15);
                printf("Child C is awake\n");
            }
            else
            {
                completedC = waitpid(childC, NULL, 0);
		if(completedC == -1){
			printf("waitpid failed");
			return 0;
		}
		printf("Parent Terminated");
            }
        }
    }
    return 0;
    }
