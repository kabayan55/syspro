#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUFSIZE 512

int main(int argc, char *argv[]){
  int data;
  FILE *fp;
  int i,j,k;
  

  if(argc != 5){
    fprintf(stderr,"Usage:pickavalue <filename>\n");
    exit(EXIT_FAILURE);
  }

  if ((fp = fopen (argv[1],"rb")) == NULL){
    perror("argv[1]");
    exit (EXIT_FAILURE);
  }

  i = atoi(argv[2]);
  j = atoi(argv[3]);
  k = atoi(argv[4]);

  fseek(fp,(50*50*i+50*j+k)*4,SEEK_SET);
  
  if(fread(&data,sizeof(int),1,fp) != 1){
    perror("data");
    fclose(fp);
    exit(EXIT_FAILURE);
  }
 
  printf("The value of (%d,%d,%d) is %d\n",i,j,k,data);

  if(fclose(fp) == EOF){
    perror("array.bin");
    exit (EXIT_FAILURE);
  }
}


