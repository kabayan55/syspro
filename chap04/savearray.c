#include <stdio.h>
#include <stdlib.h>


int main(){
  int data[50][50][50];
  FILE *fp1, *fp2;
  int i, j, k;

  /*ファイルをテキスト書込みモードで開く*/
  if ((fp1 = fopen ("array.txt","w")) == NULL){
    perror("array.txt");
    exit (EXIT_FAILURE);
  }
  /*ファイルをバイナリ読込みモードで開く*/
  if ((fp2 = fopen ("array.bin","wb")) == NULL){
    perror("array.bin");
    exit (EXIT_FAILURE);
  }

  for(i=0;i<50;i++){
    for(j=0;j<50;j++){
      for(k=0;k<50;k++){
	data[i][j][k] = rand();
	fwrite(&data[i][j][k],sizeof(int),1,fp2);
	fprintf(fp1,"%d.",data[i][j][k]);
      }
    }
  }
 
  /*テキストファイルを閉じる*/
  if(fclose(fp1) == EOF){
    perror("array.txt");
    exit (EXIT_FAILURE);
  }
  

  /*バイナリファイルを閉じる*/
  if(fclose(fp2) == EOF){
    perror("array.bin");
    exit (EXIT_FAILURE);
  }
}



