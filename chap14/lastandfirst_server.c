#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
 unsigned short port; 
 int srcSocket;  // 自分
 int dstSocket;  // 相手

 /* sockaddr_in 構造体 */
 struct sockaddr_in srcAddr;
 struct sockaddr_in dstAddr;
 unsigned int dstAddrSize = sizeof(dstAddr);

 /* 各種パラメータ */
 int numrcv;
 char buffer[BUFFER_SIZE];

 if(argc!=2){
   fprintf(stderr,"Usage: %s <port>\n", argv[0]);
   exit(EXIT_FAILURE);
 }

 // ソケットの生成
 srcSocket = socket(PF_INET, SOCK_STREAM, 0);  
 
 //ポート番号等の情報と統合（バインド）
  port=(unsigned short)atoi(argv[1]);
 // sockaddr_in 構造体のセット
 memset(&srcAddr, 0, sizeof(srcAddr));
 srcAddr.sin_port = htons(port);
 srcAddr.sin_family = PF_INET;
 srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);
 printf("Address = %s, Port = %u\n",inet_ntoa(srcAddr.sin_addr),port);
 bind(srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));  

 // 接続の許可
 listen(srcSocket, 1); 

 printf("Waiting for connection ...\n");
 dstSocket = accept(srcSocket, (struct sockaddr *) &dstAddr, &dstAddrSize);// 接続の受付
 printf("Connected from %s\n", inet_ntoa(dstAddr.sin_addr));

 char message[256];
 char shiritori[BUFFER_SIZE] = "hello";

 // パケット受信 
 while(1) { 
   memset(buffer,0,BUFFER_SIZE);
   numrcv = recv(dstSocket, buffer, BUFFER_SIZE, 0); 
   if(numrcv == 0 || numrcv == -1) {
     int status = close(dstSocket); 
     break;
   }
   strcat (shiritori, "->");
   strcat (shiritori, buffer);
   printf("%s\n", shiritori);
   send(dstSocket, buffer, numrcv, 0); 

   memset(message, 0, BUFFER_SIZE);
   printf("next>");
   fgets(message,255,stdin);
   message[strlen(message)-1]='\0';
   send(dstSocket, message, strlen(message), 0);
   numrcv  = recv(dstSocket,buffer, BUFFER_SIZE,0);
   if(numrcv == 0  || numrcv == -1 ){
     close(dstSocket);
     break;
   }
   
   if(strncmp(buffer,"quit",4)==0){
     break;
   }
 }
}
