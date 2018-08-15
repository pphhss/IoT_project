#define PORT_NUMBER     8080
#define SERVER_ADDRESS  "192.168.131.1"
#define fileMaxLength 200
#define BUFFERSIZE 2147479552


void requestSocket(int*,char *,short);    
void sendImage(char *,int);
void releaseSocket(int);
