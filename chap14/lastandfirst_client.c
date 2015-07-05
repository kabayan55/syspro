#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256 //バッファサイズ

int main(int argc,char *argv[]) {
  char *destination;    //サーバのアドレス
  unsigned short port;  //サーバのポート番号
  int dstSocket;        //ソケットID
  struct sockaddr_in dstAddr; //ソケットアドレス構造体
  int numrcv;           //recvで受け取る文字数
  char buffer[BUFFER_SIZE]; ///通信用バッファ
  char shiritori[BUFFER_SIZE];

  if(argc!=3){
    fprintf(stderr,"Usage: %s <address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  destination=argv[1];
  port=(unsigned short)atoi(argv[2]);

  /* sockaddr_in 構造体のセット */
  memset(&dstAddr, 0, sizeof(dstAddr));
  dstAddr.sin_port = htons(port);
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_addr.s_addr = inet_addr(destination);
 
  /* ソケット生成 */
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);

  /* 接続 */
  printf("Trying to connect to %s: \n", destination);
  connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr));
  printf("hello\n");

  int first_flg=1;

  char message[256];

  while(1){
    memset(message,0,BUFFER_SIZE);
    printf("next> ");
    fgets(message,255,stdin);
    message[strlen(message)-1]='\0';
    send(dstSocket,message,strlen(message),0);
    numrcv  = recv(dstSocket,buffer, BUFFER_SIZE,0);
    if(numrcv == 0  || numrcv == -1 ){
      close(dstSocket);
      break;
    }
    memset (buffer, 0, BUFFER_SIZE);
    numrcv = recv (dstSocket, buffer, BUFFER_SIZE, 0);
    if (numrcv == 0 || numrcv == -1) {
      int status = close (dstSocket);
      break;
    }
    strcat(shiritori, " -> ");
    strcat(shiritori, buffer);
    printf("%s\n", shiritori);
    
    
    if(strncmp(buffer,"quit",4)==0){
      printf("WIN!!\n");
      break;
    }
  }
  /* ソケット終了 */
  close(dstSocket);
}

