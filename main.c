#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"network.h"

#define STRINGSIZE 1000

void capture(char *);
int main(int argc, char** argv){

  int cSocket;
  char* address = "192.168.0.33";
  short port = 8080;
  

  char filePath[STRINGSIZE];
  char imagePath[STRINGSIZE];
  info datas[2];

  strcpy(datas[0].name, "name");
  strcpy(datas[0].value,argv[1]);

  
  strcpy(datas[1].name, "good");
  strcpy(datas[1].value, "hello");

  strcpy(imagePath,argv[2]);
  strcpy(filePath,argv[2]);
  
  capture(imagePath);

  printf("--------------------------------------------------------\n");

  requestSocket(&cSocket,address,port);
  
  printf("%d %s\n",cSocket,filePath);

  
  sendData(datas,2,cSocket);
  sleep(1);
  printf("sleep well!\n");
  sendImage(filePath,cSocket);

  releaseSocket(cSocket);
}
