#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include<sys/sem.h>

#define BUFSIZE 512

int main(){
  int id,rsid,wsid;
  char *adr;


  union semun rinival;
  struct sembuf rsemlock;

  union semun winival;
  struct sembuf wsemlock;

  
  rsemlock.sem_num=0;
  rsemlock.sem_flg=0;

  wsemlock.sem_num=1;
  wsemlock.sem_flg=0;

  if((id=shmget(IPC_PRIVATE,BUFSIZE,IPC_CREAT|0666))==-1){
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  if((rsid = semget (id,1,IPC_CREAT|0700)) == -1)
    {
	perror("semget");
	exit(EXIT_FAILURE);
    }
  rinival.val = 0;
  semctl(rsid,0,SETVAL,rinival);

  if((wsid = semget (id+1,1,IPC_CREAT|0700)) == -1)
    {
	perror("semget");
	exit(EXIT_FAILURE);
    }
  winival.val = 1;
  semctl(wsid,0,SETVAL,winival);


  printf("Shared memory ID =%d\n",id);
  
  if((int)(adr=shmat(id,(void *)0,0))==-1){
     perror("shmat");     
     shmctl(id,IPC_RMID,NULL);
     exit(EXIT_FAILURE);
  }

  strcpy(adr,"Initial");

  while(1){
    
    rsemlock.sem_num=0;
    rsemlock.sem_op=-1;
    rsemlock.sem_flg=0;
    if(semop(rsid,&rsemlock,1)<0) break;

    printf("%s\n",adr);

    wsemlock.sem_num=0;
    wsemlock.sem_op=1;
    wsemlock.sem_flg=0;
    if(semop(wsid,&wsemlock,1)<0) break;

    if(strncmp(adr,"quit",4)==0){
      break;
    }
  }
     
  if(shmdt(adr)==-1){
    perror("shmdt");
    shmctl(id,IPC_RMID,NULL);
    exit(EXIT_FAILURE);
  }

  if(shmctl(id,IPC_RMID,NULL)==-1){
     perror("shmctl");
     exit(EXIT_FAILURE);
  }
}
