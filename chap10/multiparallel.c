#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  pid_t ret;
  int i, j, counter;
  int pid[20];
  int status;

  if(argc != 2){
    fprintf(stderr, "Usage : %s <num>\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  counter = atoi(argv[1]);
  printf("[BEFORE FORK]\n Process ID: \%d\t Parent Proces ID : %d\n", getpid(), getppid());


  for(j =0; j<counter; j++){
    ret = fork(); 
    srand (time (NULL));
    if(ret==0){
      printf("[AFTER FORK]\n Process ID: \%d\t Parent Proces ID : %d\n", getpid(), getppid());

      printf("[id=%d] Return Value of Fork : %d\n", getpid(),ret);
      printf("\n");
    }
    sleep(1);


    if (ret>0){
      pid[j]=ret;
    }
    else if(ret==0){
      for(i=0; i<5; i++){
    printf("(%d) for loop i = %d\n", getpid(), i);
    sleep(rand() % 3);
  }
 
      printf("(%d) End of the child process\n", getpid());
      break;
  }
    else{
      perror("ERROR");
      exit(EXIT_FAILURE);
    }
  }
  if (ret>0){
    for(j=0; j<counter; j++){
      waitpid(pid[j], &status, WUNTRACED);
    }
    printf("(%d) End of the parent process\n", getpid());
    }
}
  
