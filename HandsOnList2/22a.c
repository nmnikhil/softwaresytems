#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main () {
char buff [90];
int fd = open ("nick",O_WRONLY);
 printf("Enter the text:");
 scanf(" %[^\n]", buff);
 write(fd, buff, sizeof(buff));
}
