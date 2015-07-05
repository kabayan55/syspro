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
 int srcSocket;  // ����
 int dstSocket;  // ����

 /* sockaddr_in �\���� */
 struct sockaddr_in srcAddr;
 struct sockaddr_in dstAddr;
 unsigned int dstAddrSize = sizeof(dstAddr);

 /* �e��p�����[�^ */
 int numrcv;
 char buffer[BUFFER_SIZE];

 if(argc!=2){
   fprintf(stderr,"Usage: %%server <port>\n");
   exit(EXIT_FAILURE);
 }

 // �\�P�b�g�̐���
 srcSocket = socket(PF_INET, SOCK_STREAM, 0);  
 
 //�|�[�g�ԍ����̏��Ɠ����i�o�C���h�j
  port=(unsigned short)atoi(argv[1]);
 // sockaddr_in �\���̂̃Z�b�g
 memset(&srcAddr, 0, sizeof(srcAddr));
 srcAddr.sin_port = htons(port);
 srcAddr.sin_family = PF_INET;
 srcAddr.sin_addr.s_addr = htonl(INADDR_ANY);
 printf("Address = %s, Port = %u\n",inet_ntoa(srcAddr.sin_addr),port);
 bind(srcSocket, (struct sockaddr *) &srcAddr, sizeof(srcAddr));  

 // �ڑ��̋���
 listen(srcSocket, 1); 

 printf("Waiting for connection ...\n");
 dstSocket = accept(srcSocket, (struct sockaddr *) &dstAddr, &dstAddrSize);// �ڑ��̎�t
 printf("Connected from %s\n", inet_ntoa(dstAddr.sin_addr));

 // �p�P�b�g��M 
 while(1) { 
   memset(buffer,0,BUFFER_SIZE);
   numrcv = recv(dstSocket, buffer, BUFFER_SIZE, 0); 
   if(numrcv == 0 || numrcv == -1) {
     int status = close(dstSocket); break;
   }
   printf("received: %s\n", buffer);
   send(dstSocket, buffer, numrcv, 0); 
   if(strncmp(buffer,"quit",4)==0) break;
 }
}
