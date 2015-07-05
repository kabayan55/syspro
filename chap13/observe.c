#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main(int argc,char *argv[]){
  int idA,idB,tmp,i,sid;
  int *A, *B;
  int *counter;
  int num;
  struct shmid_ds buf;
  struct sembuf semlock;
  union semun inival;

  semlock.sem_num = 0;
  semlock.sem_flg = 0;


  srand((unsigned) time(NULL)); //rand()‚Å–ˆ‰ñˆá‚¤—”‚ğ”­¶‚³‚¹‚é

  if(argc!=3){ //‚·‚Å‚Éì¬‚³‚ê‚½‹¤—Lƒƒ‚ƒŠ‚ğg‚¤
    fprintf(stderr,"Usage: %s <shmA ID> <shmB ID>",argv[0]);
    exit(EXIT_FAILURE);
  }
  idA=atoi(argv[1]);
  idB=atoi(argv[2]);
    
 if((sid = semget(idA, 1, 0)) == -1){
    perror("semget");
    exit(EXIT_FAILURE);
  }

  A = (int *)shmat(idA,0,0);
  B = (int *)shmat(idB,0,0);  
  
  while(*A>0){
    semlock.sem_num = 0;
    semlock.sem_op = -1;
    semlock.sem_flg = 0;
    if(semop(sid, &semlock, 1) < 0){
      break;
    }

    printf("A=%d, B=%d, A+B=%d\n",*A,*B,(*A)+(*B));
    
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
