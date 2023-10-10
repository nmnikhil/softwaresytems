/*
============================================================================
Name : 30.c
Author : NIKHIL NM 
Description : Write a program to run a script at a specific time using a Daemon process.
Date : 8th September 2023
============================================================================
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/stat.h>
void main(int argc, char *argv[])
{

    time_t currVal, terminateVal; 
    struct tm *completed;

    pid_t child;

    if (argc < 2)
        printf("Wrong number of arguments\n");
    else
    {
        time(&currVal);
        completed = localtime(&currVal);

        completed->tm_hour = atoi(argv[1]);
        completed->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
        completed->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

        terminateVal = mktime(completed);
	pid_t child = fork();
        if (child == 0)
        {
            setsid();
            chdir("/");//root
            umask(0);
            do
            {
                printf("Executing");
		time(&currVal);
            } while (difftime(terminateVal, currVal) > 0);
            exit(0);
        }
        exit(0);
    }
}
