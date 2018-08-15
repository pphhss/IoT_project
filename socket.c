#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>

void requestSocket(int *cSocket, char *address, short port){

  struct sockaddr_in server_addr;

  *cSocket = socket(PF_INET,SOCK_STREAM,0);

  if(*cSocket==-1){
    fprintf(stderr,"Error of creating Socket\n");
    exit(1);
  }

  memset(&server_addr,0,sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(address);

  if((connect(*cSocket,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)){
    fprintf(stderr,"Error of connecting\n");
    exit(1);

  }





}

void releaseSocket(int cSocket){

  close(cSocket);
}
