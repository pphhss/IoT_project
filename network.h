
typedef struct{
  char name[20];
  char value[20];
}info;

void requestSocket(int*,char *,short);    
void sendImage(char *,int);
void releaseSocket(int);
void sendData(info datas[], int length, int cSocket);
