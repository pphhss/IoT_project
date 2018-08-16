#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/socket.h>

#include "network.h"

#define BUFFERSIZE 2147479552
#define TEXTBUFFERSIZE 2000


void infoToString(char *text, info datas[],int length){

  char tmp[TEXTBUFFERSIZE];
  if(length<1){
    fprintf(stderr,"a length of datas is short\n");
    exit(1);
  }
  strcat(text,"{");
  for(int i=0;i<length;i++){
    memset(tmp,0,strlen(tmp));

    sprintf(tmp,"\"%s\" : \"%s\",",datas[i].name,datas[i].value);
    strcat(text,tmp);

  }

  strcat(text,"}");

}

void sendImage(char *filePath,int cSocket)
{

/*
  Send an image file to central server.
  
  parameter:
    filePath - a path of file which is sended to server.
    cSocket - client socket

*/
        struct stat file_stat;
        int fd;
        ssize_t sent_bytes;
        int remain_bytes;
        off_t offset;






        fd = open(filePath,O_RDONLY);

        if(fd == -1){
          fprintf(stderr,"Error open\n.");
          exit(-1);
        }

        if(fstat(fd,&file_stat)<0){
          fprintf(stderr, "Error fstat\n");
          exit(-1);
        }
        remain_bytes = file_stat.st_size;
        offset =0;
        printf("FilePath : %s / FileSize : %d byte\n",filePath,remain_bytes);

  if((sent_bytes=sendfile(cSocket,fd,&offset,BUFFERSIZE))<0){
    fprintf(stderr,"Error sendfile\n");
    close(fd);
    exit(-1);
  }

        printf("Success to transfer datas\n");

        close(fd);

        /* Receiving file size */



}
void sendData(info datas[], int length, int cSocket){
/*
  Send a data to central server

  parameter:
    info datas[] - a data in type of 'info' which is sended to server.
    int length - 

*/
  char sendData[TEXTBUFFERSIZE];
  char its[TEXTBUFFERSIZE];

  memset(sendData,0,TEXTBUFFERSIZE);
  memset(its,0,TEXTBUFFERSIZE);

  infoToString(its,datas,length);

  strcpy(sendData,"^DATA^");

  strcat(sendData,its);
  

  write(cSocket,sendData,strlen(sendData));
}
