#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char *src, *dest, *a;
  char path[256];
  char trashdir[256];
  DIR *directory;
  struct dirent *ent;
  int len;

  sprintf(trashdir,"%s/%s",getenv("HOME"), ".Trash");
  len = strlen(argv[1]); 
  a = argv[1] + len -1; 
  while(*a != '/'){
    a--;
  }
  strcpy(path, argv[1]);
  strcat(trashdir, a);
  link(argv[1], trashdir);
  unlink(path);
}



