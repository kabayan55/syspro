#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sem.h>

int main(int argc,char *argv[]){
  int id,rsid,wsid;
  char *adr;

  union semun rinival;
  struct sembuf rsemlock;

  union semun winival;
  struct sembuf wsemlock;

  
  rsemlock.sem_num = 0;
  rsemlock.sem_flg = 0;

  wsemlock.sem_num = 1;
  wsemlock.sem_flg = 0;


  if(argc!=2){
    fprintf(stderr,"Usage: send <Shared memory ID>");
    exit(EXIT_FAILURE); 
  }
  
  id = atoi(argv[1]);
  if((int)(adr=shmat(id,(void *)0,0))==-1){
    perror("shmat");
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


  while(1){   
    wsemlock.sem_num = 0;
    wsemlock.sem_op = -1;
    wsemlock.sem_flg = 0;
    if(semop(wsid,&wsemlock,1) < 0){
      break;
    }
    printf("Input any string>");
    fgets(adr,512,stdin);     
    adr[strlen(adr)-1]='\0';

    rsemlock.sem_num = 0;
    rsemlock.sem_op = 1;
    rsemlock.sem_flg = 0;
    if(semop(rsid,&rsemlock,1)<0) {
      break;
    }
    if(strcmp(adr,"quit")==0){
      break;
    }
  }
  if(shmdt(adr)==-1){
    perror("shmdt");
    exit(EXIT_FAILURE);
  }
}
