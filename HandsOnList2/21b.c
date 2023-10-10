#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (){
char buff1[80];
char buff2[80];
int fd1 = open ("nick1",O_RDONLY);
int fd2 = open ("nick2",O_WRONLY);
read(fd1, buff2, sizeof(buff2));
printf("The text from second  FIFO file: %s\n", buff2);

printf("Enter the text:");
scanf(" %[^\n]", buff1);
write(fd2, buff1, sizeof(buff1));
 
}
