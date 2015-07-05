#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double
getETime()
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec + (double) tv.tv_usec * 1e-6;
}

int
main(int argc, char *argv[])
{
  FILE *fpin, *fpout;
  int readsize,COPYSIZE=16384;
  double st,en;
  char c[16384];

  if(argc != 3)
    {
      fprintf(stderr,"Usage: copy_highio<コピー元><コピー先>\n");
      exit(EXIT_FAILURE);
    }
  /*コピー元ファイルを開く*/
  if((fpin = fopen(argv[1],"rb")) == NULL)
    {
      perror(argv[1]);
      exit(EXIT_FAILURE);
    }
  /*コピー先ファイルを開く*/
  if((fpout = fopen(argv[2],"wb")) == NULL)
    {
      perror(argv[2]);
      exit(EXIT_FAILURE);
    }

  st = getETime();
  while((readsize = fread(c,sizeof(COPYSIZE),1,fpin)) >0)
    {                   /*256バイト読込む*/
      fwrite(c,sizeof(readsize),1,fpout); /*256バイト書き込む*/
    }
  en = getETime();

  fclose (fpin);
  fclose (fpout);

  printf("Elapsed Time: %.6f\n", en - st);
}
