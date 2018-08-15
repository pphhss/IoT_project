#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#include "network.h"

void sendImage(char *filePath,int cSocket)
{
        ssize_t len;
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

