#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]){
  FILE *fpin, *fpout;
  int c;

  //(1) main引数のエラー処理
  if(argc<3){
    fprintf(stderr,"Usage:copy <コピー先><コピー元>\n");
    exit(EXIT_FAILURE);
  }
  
  //(2) コピー元を読込みで開く
  if((fpin = fopen (argv[1],"r")) ==NULL){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  //(3) コピー先を書込みで開く
  if((fpout = fopen (argv[2],"w")) ==NULL){
    perror(argv[2]);
    exit(EXIT_FAILURE);
  }

  //(4) 
  while((c=fgetc(fpin)) != EOF)
    fputc(c,fpout);

  //(6) コピー元ファイルを閉じる
  if(EOF==fclose(fpin)){
    perror(argv[1]);
    exit(EXIT_FAILURE);
  }
  //(7) コピー先ファイルを閉じる
  if(EOF==fclose(fpout)){
    perror(argv[2]);
    exit(EXIT_FAILURE);
  }
}
