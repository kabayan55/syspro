#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
  struct stat st;
  mode_t filetype;

  if(argc !=2){
    fprintf(stderr,"Usage: %s <filepath>\n",argv[0]);
    exit(EXIT_FAILURE);
  }
  if(lstat(argv[1],&st)<0){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  filetype = st.st_mode & ~S_IFMT;
  
 
  printf(" For user:");
  if((filetype & (1<<8)) == 1<<8){
    printf(" read");
  }
  if((filetype & (1<<7)) == 1<<7){
    printf(" write");
  }
  if((filetype & (1<<6)) == 1<<6){
    printf(" execute");
  }
  printf("\n For groups:");
  if((filetype & (1<<5)) == 1<<5){
    printf(" read");
  }
  if((filetype & (1<<4)) == 1<<4){
    printf(" write");
  }
  if((filetype & (1<<3)) == 1<<3){
    printf(" execute");
  }
  printf("\n For others:");
  if((filetype & (1<<2)) == 1<<2){
    printf(" read");
  }
  if((filetype & (1<<1)) == 1<<1){
    printf(" write");
  }
  if((filetype & (1)) == 1){
    printf(" execute");
  }
  printf("\n");
}
