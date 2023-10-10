#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
char buff[90];
int fd = open ("nick",O_RDONLY);
 read(fd, buff, sizeof(buff));
 printf("The text from FIFO file: %s\n", buff);
}
