#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
  
int main()
{
    // array of 2 size a[0] is for reading 
    // and a[1] is for writing over a pipe 
    int a[2]; 
  
    // opening of pipe using pipe(a)   
    char buff[1024];
    if (pipe(a) == -1) 
    {
        perror("pipe"); // error in pipe
        exit(1); // exit from the program
    }
  
    // writing a string "code" in pipe
    write(a[1], "writing into the pipe", sizeof(buff)); 
    printf("\n");
  
    // reading pipe now buff is equal to "code"
    read(a[0], buff, sizeof(buff));
  
    // it will print "code"
    printf("%s", buff); 
}

