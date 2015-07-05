#include <stdio.h>
#include <stdlib.h>

char B64MapTable[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

int main(int argc,char *argv[]){
	char B64MapTable[64];
	unsigned char c,bin[3],tmp[4],txt[4];
	FILE *fp,*fp2;
	int i=0,e;
		
    if((fp=fopen(argv[1],"rb"))==NULL){
      fprintf(stderr,"cannot open the file %s\n",argv[1]);
      exit(EXIT_FAILURE);
    }
	

    if((fp2=fopen(argv[2],"w"))==NULL){
      fprintf(stderr,"cannot open the file %s\n",argv[2]);
      exit(EXIT_FAILURE);
    }

	while((e=fread(bin,sizeof(char),3,fp))>0){
		//余ったところに0を詰め込む
		if(e<3)for(i=e;i<4;i++)bin[i]=0;
		
		//6ビットずつに分ける
		tmp[0]= bin[0]>>2;
		tmp[1]=( (bin[0]&0x03)<<4 ) | ((bin[1]&0xF0)>>4);
		tmp[2]=( (bin[1]&0x0F)<<2 ) | ((bin[2]&0xC0)>>6);
		tmp[3]=( bin[2]&0x3F );
		
		//テキストに変換する
		if(e==3)
		  for(i=0;i<4;i++){
			txt[i]=B64MapTable[tmp[i]];
			fputc(txt[i],fp2);
		  }
		else{
		  for(i=0;i<=e;i++){
		    txt[i]=B64MapTable[tmp[i]];
		    fputc(txt[i],fp2);
		  }
		  for(i=e;i<3;i++)
		    fputc('=',fp2);
		}
	}
	
	fclose(fp);
	fclose(fp2);
	
}
