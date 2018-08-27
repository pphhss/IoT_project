#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include"network.h"

#define STRINGSIZE 1000

void capture(char *);
int main(int argc, char** argv){

  int sSocket=0;
  short port = 8080;
  
  char receive[100];
  int receiveSize = 100;

  openServer(&sSocket,port);

  listenServer(&sSocket,receive,receiveSize);
  
}
