#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main(int argc,char *argv[]){
  int idA,idB,tmp,i,sid;
  int *A, *B;
  int num;
  int tmpA,tmpB;
  struct shmid_ds buf;
  union semun inival;
  struct sembuf semlock;

  semlock.sem_num = 0;
  semlock.sem_flg = 0;
  
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

    if((sid = semget(idA, 1, IPC_CREAT|0700)) == -1){
      perror("semget");
      exit(EXIT_FAILURE);
    }
    inival.val = 1;
    semctl(sid, 0, SETVAL, inival);

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
    
    semlock.sem_num = 0;
    semlock.sem_op = -1;
    semlock.sem_flg = 0;
    if(semop(sid, &semlock, 1) < 0){
      break;
    }

    tmpA=*A;
    tmpB=*B;
    tmpA-=1;
    tmpB+=1;
    *A=tmpA;
    usleep((rand()%10)*100000);
    *B=tmpB;
    if(*A==0){
      break;
    }
    semlock.sem_num = 0;
    semlock.sem_op = 1;
    semlock.sem_flg = 0;
  if(semop(sid, &semlock, 1) < 0){
    break;
  }
  
  sleep(rand() % 4);
  }
  
  shmctl(idA,IPC_STAT,&buf);
  
  if(shmdt(A)==-1)perror("shmdt");
  if(shmdt(B)==-1)perror("shmdt");
  if(buf.shm_nattch==1){
    if(shmctl(idA,IPC_RMID,0)==-1) perror("chmctl");
    if(semctl(sid,IPC_RMID,0)==-1) perror("semctl");
    if(shmctl(idB,IPC_RMID,0)==-1) perror("chmctl");
  } 
}
