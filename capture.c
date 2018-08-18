#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void capture(char *path){

  char command[100];

  memset(command,0,100);

  sprintf(command,"fswebcam -r 1280x720 %s",path);

  system(command);


}
