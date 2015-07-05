#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[]){
  char *src, *dest, *i;
  char path[256];
  char trashdir[256];
  DIR *directory;
  struct dirent *ent;
  int len;

  sprintf(trashdir,"%s/%s",getenv("HOME"), ".Trash");
  len = strlen(argv[1]); 
  i = argv[1] + len -1; 
  while(*i != '/'){
    i--;
  }
  strcpy(path, argv[1]);
  strcat(trashdir, i);
  link(argv[1], trashdir);
  unlink(path);
}
