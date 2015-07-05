#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  DIR *directory;
  struct dirent *ent; /*ディレクトリエントリ構造体*/
  struct stat st;
  mode_t filetype;
  char name[256],str[256];
  int a,y,n,q,l;
  
  if(argc !=2){
    fprintf(stderr,"Usage: %s <filepath>\n",argv[0]);
    exit(EXIT_FAILURE);
  }

  /*(1)ディレクトリを開く*/
  directory = opendir (argv[1]);
  if(!directory){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  /*(2)ディレクトリエントリからファイル名を取出し*/
  while ((ent = readdir (directory)) != NULL){
    strcpy(name,argv[1]);
    strcat(name,"/");
    strcat(name,ent->d_name);
    strcpy(str,name);
    
    l=strlen(str);
    if (str[l-1]=='~'){
      printf("Do you remove the file %s ? [y/n/q]\n",str);
      scanf("%c",&a);
      getchar();
      if(a=='y'){
	if(unlink(name)!=0){
	  perror(name);
	  exit(EXIT_FAILURE);
      }
	if(a=='n'){
	  return -1;
	}
	if(a=='q'){
	  break;
	}     
      }
    }
  } 
  /*(3)ディレクトリを閉じる*/
  closedir(directory);
}
