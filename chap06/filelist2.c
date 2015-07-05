#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[]){
  DIR *directory;
  struct dirent *ent; /*ディレクトリエントリ構造体*/
  struct stat st;
  mode_t filetype;
  char name[256];

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

  if (lstat (name, &st) <0){
      perror(name);
      exit(EXIT_FAILURE);
    }



    filetype = st.st_mode & S_IFMT;
    switch(filetype){
    case S_IFDIR:
      printf("%s/\n",ent->d_name);
      break;
    case S_IFLNK:
      printf("%s@\n",ent->d_name);
      break;
    }
  }
  /*(3)ディレクトリを閉じる*/
  closedir(directory);
}


