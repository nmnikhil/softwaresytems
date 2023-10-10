/*
============================================================================
Name : 14.c
Author : NIKHIL NM 
Description : Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
   

    const char* filePath = argv[1];
    struct stat fileStat;

    if (stat(filePath, &fileStat) == -1) {
        perror("Error");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode)) {
        printf("Regular file: %s\n", filePath);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Directory: %s\n", filePath);
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("Symbolic link: %s\n", filePath);
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("Socket: %s\n", filePath);
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("Character device: %s\n", filePath);
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("Block device: %s\n", filePath);
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("FIFO/pipe: %s\n", filePath);
    } else {
        printf("Unknown file type: %s\n", filePath);
    }

    return 0;
}
