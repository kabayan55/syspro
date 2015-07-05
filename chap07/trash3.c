#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>


int main(int argc, char *argv){
  DIR *directory;
  struct dirent *ent; /*ディレクトリエントリ構造体*/
  char name[256],str[256],*a[256],trashdir[256];
  
  if(argc !=2){
    fprintf(stderr,"Usage: %s <filepath>\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  strcpy(str, argv[1]);
  a = strtok(str,"/");
  while((a=strtok(NULL,"/")) != NULL){
    strcat(name,str);
  }
  
  sprintf(trashdir,"%s/%s/%s",getenv("HOME"),".Trash",name);
  
  if(link(argv[1],trashdir)!=0){
    perror(name);
    exit(EXIT_FAILURE);
  }  
  if(unlink(argv[1])!=0){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
}
