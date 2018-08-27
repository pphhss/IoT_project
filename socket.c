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

void openServer(int *sSocket,short port){

  struct sockaddr_in server_addr;

  *sSocket = socket(PF_INET,SOCK_STREAM,0);
  if(*sSocket==-1){
    printf("can't create serverSocket\n");
    exit(1);
  }

  memset(&server_addr,0,sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if(bind(*sSocket,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1){
    printf("server socket bind error\n");
    exit(1);
  }

  printf("Server Socket Open! - %d\n",*sSocket);

  

}

void listenServer(int *sSocket,char* buffer, int size){

  int caddr_size=0;
  int cSocket=0;
  struct sockaddr_in caddr;
  
  memset(buffer,0,size);

  if(listen(*sSocket,5)==-1){
    printf("fail to listen..\n");
    exit(1);
  }

  caddr_size = sizeof(caddr);
  
  printf("listen..\n");
  cSocket = accept(*sSocket,(struct sockaddr*)&caddr,&caddr_size);

    if(cSocket==-1){
      printf("server cant accept client!\n");
      sleep(1);
    }

  read(cSocket,buffer,size);

  printf("receive : %s\n",buffer);
  
  close(cSocket);

  close(*sSocket);

}
