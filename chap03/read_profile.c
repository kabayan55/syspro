#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define BUFSIZE 512

typedef struct profile{
  char name[24];
  int age;
}profile;

int main(int argc, char *argv[]){
  FILE *fp;
  char buf[BUFSIZE],*token;
  int i=0;
  struct profile a[20];


  if(argc != 2){
    fprintf(stderr, "Usage: read_profile <filename>\n");
    exit(EXIT_FAILURE);
  }
  
  if((fp=fopen(argv[1],"r"))==NULL){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  

  while(fgets(buf,BUFSIZE-1,fp)!=NULL){  
    token=strtok(buf,",");
    if(token==NULL){
      return -1;
    } 

    strcpy(a[i].name,token);    
    token=strtok(NULL,"\n");
    if(token==NULL){
      return -1;
    }
    
    a[i].age=atoi(token);    
    
    printf("[NO.%d]\n",i);
    printf(" name=%s\n",a[i].name);
    printf(" age=%d\n",a[i].age);
    i++;
    if(i>=20){
      printf("after the 20th column non display\n");
  return -1;
  }
}
  
  if(fclose(fp) == EOF){
  perror(argv[1]);
  exit(EXIT_FAILURE);
  }
}
