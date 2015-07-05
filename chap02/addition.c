#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){
  char *ptr1,*ptr2;
  long a,b,c;

  if(argc != 3){
    fprintf(stderr,"Usage: %s <num> <num>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  a = strtol (argv[1],&ptr1,10);
  b = strtol (argv[2],&ptr2,10);

  if(errno == EINVAL || errno == ERANGE){
    perror("ERROR(addition)");
    exit(EXIT_FAILURE);
  }

  else if(errno != 0){
    perror("Unexpected ERROR(addition)");
    exit (EXIT_FAILURE);
  }
 

  else if(*ptr1 != '\0' || *ptr2 != '\0'){
    printf("ERROR(addition):Please input number only.\n");
    exit(EXIT_FAILURE);
}
  

  c = a + b;
  printf("%d + %d = %d\n",a,b,c);
}
