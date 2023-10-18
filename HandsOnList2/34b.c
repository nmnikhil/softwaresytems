#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    //server and client are on same machine so we use local host ip 127.0.0.1 and any port > 5000
    
    char *ip="127.0.0.1";
    int port=5566; 
    int sock;
    
    struct sockaddr_in addr;
    socklen_t addr_size;
    char buffer[1024];
    int n;
    
   sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("socket error");
        exit(1);
    }
    memset(&addr,'\0',sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=port;
    addr.sin_addr.s_addr=inet_addr(ip);
    connect(sock,(struct sockaddr*)&addr,sizeof(addr));
    printf("[+] Connected To Server... \n");
    
    
    
    //strcpy(buffer,"i am client");
    printf("Msg To Server :\n");
    read(0,&buffer,sizeof(buffer));
    send(sock,buffer,strlen(buffer),0);
    
     bzero(buffer,1024);
     
     recv(sock,buffer,sizeof(buffer),0);
     printf("Server : %s\n",buffer);
     
     close(sock);
     printf("[+] Disconnected form sever \n\n");
}
