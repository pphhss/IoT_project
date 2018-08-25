
typedef struct{
  char key[20];
  char value[20];
}info;

void requestSocket(int*,char *,short);    
void sendImage(char *,int);
void releaseSocket(int);
void sendData(info datas[], int length, int cSocket);
void getType0(info*,char*,char*,char*,char*,char*);
void getType1(info*,char*);
