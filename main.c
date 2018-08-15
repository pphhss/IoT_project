#include<stdio.h>
#include<string.h>
#include"send.h"

#define STRINGSIZE 1000
int main(int argc, char** argv){


  char filePath[STRINGSIZE];

  strcpy(filePath,argv[1]);


  sendImage(filePath);



}
