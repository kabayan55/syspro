#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 512

int main(){
  FILE *fpin, *fpout;
  int XL,YL,i,x,y;
  char buf[BUFSIZE],a[256],b[256],*n,data1,data2;


  /*ファイルをバイナリ読込みモードで開く*/
  if((fpin = fopen ("kumamon.ppm","rb")) == NULL){
      perror("kumamon.ppm");
      exit(EXIT_FAILURE);
  }
  /*ファイルをバイナリ書込みモードで開く*/
  if((fpout = fopen ("white_kumamon.ppm","wb")) == NULL){
    perror("white_kumamon.ppm");
    exit(EXIT_FAILURE);
  }
  /*最初の４行を読込む*/
  for(i=0; i<4; i++){ 
    fgets(buf,BUFSIZE-1,fpin);
    fputs(buf,fpout);
  
    /*縦横の値をとってくる*/
    if (i==2){
      n = strtok(buf," ");
      strcpy(a,n);
      n = strtok(NULL," ");
      strcpy(b,n);
    }
  }
    XL = atoi(a);
    YL = atoi(b);
    
    /*残りのデータを読込む*/
    for (y=0; y<YL; y++){
      for (x=0; x<XL*3; x++){ /*データは全部で幅×高さ×3*/
	if(fread(&data1,sizeof(char),1,fpin) != 1){
	  perror("data1");
	  fclose(fpin);
	  exit(EXIT_FAILURE);
	}
	data2 = 255 - data1;
	fwrite(&data2,sizeof(char),1,fpout);
      }
    }
    
    /*ファイルを閉じる*/
    if(fclose(fpin) == EOF){
      perror("kumamon.ppm");
    exit(EXIT_FAILURE);
    }  
    if (fclose(fpout) == EOF){
      perror("white_kumamon.ppm");
      exit(EXIT_FAILURE);
    }
}
