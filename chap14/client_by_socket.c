#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256 //�Хåե�������

int main(int argc,char *argv[]) {
  char *destination;    //�����ФΥ��ɥ쥹
  unsigned short port;  //�����ФΥݡ����ֹ�
  int dstSocket;        //�����å�ID
  struct sockaddr_in dstAddr; //�����åȥ��ɥ쥹��¤��
  int numrcv;           //recv�Ǽ������ʸ����
  char buffer[BUFFER_SIZE]; ///�̿��ѥХåե�
  
  if(argc!=3){
    fprintf(stderr,"Usage: % laf_client <address> <port>\n");
    exit(-1);
  }
  destination=argv[1];
  port=(unsigned short)atoi(argv[2]);

  /* sockaddr_in ��¤�ΤΥ��å� */
  memset(&dstAddr, 0, sizeof(dstAddr));
  dstAddr.sin_port = htons(port);
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_addr.s_addr = inet_addr(destination);
 
  /* �����å����� */
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);

  /* ��³ */
  printf("Trying to connect to %s: \n", destination);
  connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr));

  int first_flg=1;

  char message[256];

  while(1){
    memset(message,0,256);
    printf(">");
    fgets(message,255,stdin);
    message[strlen(message)-1]='\0';
    send(dstSocket,message,strlen(message),0);
    numrcv  = recv(dstSocket,buffer, BUFFER_SIZE,0);
    if(numrcv == 0  || numrcv == -1 ){
      close(dstSocket);
      break;
    }
    printf("from server: %s \n",buffer);
    if(strncmp(buffer,"quit",4)==0)break;
  }
  /* �����åȽ�λ */
  close(dstSocket);
}
