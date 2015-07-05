#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc,char *argv[]){
  int idA,idB,tmp,sid,i;
  int *A,*B;
  int num;
  int tmpA,tmpB;

  srand((unsigned) time(NULL)); //rand()‚Å–ˆ‰ñˆá‚¤—”‚ğ”­¶‚³‚¹‚é

  if(argc!=1){ 
    fprintf(stderr,"Usage: %s\n",argv[0]);
    exit(EXIT_FAILURE);
   
  }
  
  //‹¤—Lƒƒ‚ƒŠ‚ğì¬‚·‚é
    if((idA=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666))==-1){
      perror("shmget A");
      exit(EXIT_FAILURE);
    }
    if((idB=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666))==-1){
      perror("shmget B");
      exit(EXIT_FAILURE);
    }
    printf("A's ID = %d, B's ID = %d\n",idA,idB);
  
  //‰Šú’l‚ğİ’è‚·‚é
  A = (int *)shmat(idA,0,0);
  B = (int *)shmat(idB,0,0);
  *A=100; *B=0;
  
  printf("get any key to start");
  getchar();
  
  while(1){
    tmpA=*A;
    tmpB=*B;
    tmpA-=1;
    tmpB+=1;
    usleep((rand()%10)*10000);
    *A=tmpA;
    *B=tmpB;
    if(*A==0){
      break;
    }
  }
  
  sleep(5);

  shmctl(idA,IPC_STAT,&buf);
  
  if(shmdt(A)==-1)perror("shmdt");
  if(shmdt(B)==-1)perror("shmdt");
  if(buf.shm_nattch==1){
    if(shmctl(idA,IPC_RMID,0)==-1) perror("chmctl");
    if(shmctl(idB,IPC_RMID,0)==-1) perror("chmctl");
  }
   
}
