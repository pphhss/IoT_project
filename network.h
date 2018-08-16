
typedef struct{
  char* name;
  char* value;
}info;

void requestSocket(int*,char *,short);    
void sendImage(char *,int);
void releaseSocket(int);
void sendData(info datas[], int length, int cSocket);
