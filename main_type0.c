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
  
  int sSocket=0;
  char receive[100];
  int receiveSize =100;

  info datas[6];
  int length = 6;

  getType0(datas,"1","1","36.5","60","none");

  printf("%s %s %s %s %s\n",datas[1].value,datas[2].value,datas[3].value,datas[4].value,datas[5].value);
  requestSocket(&cSocket,address,port);
  
  sendData(datas,6,cSocket);

  // serversocket open..
  openServer(&sSocket,port);

  listenServer(&sSocket,receive,receiveSize);

  
  releaseSocket(cSocket);
}
