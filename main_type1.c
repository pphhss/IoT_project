#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"network.h"

#define STRINGSIZE 1000

void capture(char *);
int main(int argc, char** argv){

  int cSocket;
  char* address = "192.168.219.165";
  short port = 8080;
  
  info datas[2];
  int length = 2;

  char* imagePath = "image.png";

  getType1(datas,"1");

  printf("%s\n",datas[1].value);
  requestSocket(&cSocket,address,port);
  
  sendData(datas,length,cSocket);


  capture(imagePath);

  printf("-----------------------------\n");
  sleep(1);

  sendImage(imagePath,cSocket);


  releaseSocket(cSocket);
}
