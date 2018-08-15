#include<stdio.h>
#include<string.h>
#include"network.h"

#define STRINGSIZE 1000
int main(int argc, char** argv){

  int cSocket;
  char* address = "192.168.131.1";
  short port = 8080;


  char filePath[STRINGSIZE];

  strcpy(filePath,argv[1]);

  requestSocket(&cSocket,address,port);
  

  sendImage(filePath,cSocket);


  releaseSocket(cSocket);
}
