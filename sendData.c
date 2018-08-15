#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define PORT_NUMBER     8080
#define SERVER_ADDRESS  "192.168.131.1"
#define fileMaxLength 200
#define BUFFERSIZE 2147479552
int main(int argc, char **argv)
{
        int client_socket;
        ssize_t len;
        struct sockaddr_in remote_addr;
        struct stat file_stat;
        int fd;
        char filePath[fileMaxLength];
        ssize_t sent_bytes;
        int remain_bytes;
        off_t offset;

        if(argc<2){
          fprintf(stderr,"Usage : %s <filepath>",argv[0]);
          exit(-1);
        }
        strcpy(filePath,argv[1]);




        /* Zeroing remote_addr struct */
        memset(&remote_addr, 0, sizeof(remote_addr));

        /* Construct remote_addr struct */
        remote_addr.sin_family = AF_INET;
        inet_pton(AF_INET, SERVER_ADDRESS, &(remote_addr.sin_addr));
        remote_addr.sin_port = htons(PORT_NUMBER); //htons : convert host byte to network byte

        /* Create client socket */
        client_socket = socket(AF_INET, SOCK_STREAM, 0); // AF_INET : use IPv4 / SOCK_STREAM : use TCP
        if (client_socket == -1)
        {
                fprintf(stderr, "Error creating socket --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
        }

        /* Connect to the server */
        if (connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
        {
                fprintf(stderr, "Error on connect --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
        }

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

  if((sent_bytes=sendfile(client_socket,fd,&offset,BUFFERSIZE))<0){
    fprintf(stderr,"Error sendfile\n");
    close(fd);
    close(client_socket);
    exit(-1);
  }

        printf("Success to transfer datas\n");

        close(fd);

        /* Receiving file size */


        close(client_socket);

        return 0;
}

