#include <stdio.h>
#include <stdlib.h>

struct profile{
  char name[18];
  int age;
  float height;
};

int main(){
  FILE *fp;
  int i;
  struct profile res;

  
  /*ファイルをバイナリ読込みモードで開く*/
  if((fp = fopen ("list_binary.bin","rb")) == NULL){
      perror("list_binary.bin");
      exit(EXIT_FAILURE);
  }

  /*構造体の配列を一度に読込む*/
  for(i=0;i<3;i++){
    fread (&res, sizeof(struct profile) ,1, fp);
    printf("[No.%d] name=%s,age=%d,height=%3.2f\n",i,res.name,res.age,res.height);
  }
if(fclose(fp) == EOF){
    perror("list_binary.bin");
    exit(EXIT_FAILURE);
  }    
 
}    
    
