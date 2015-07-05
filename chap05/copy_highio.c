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
  double st,en;
  char c;

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
  while(fread(&c,1,1,fpin) == 1)
    {                   /*1バイト読込む*/
      fwrite(&c,1,1,fpout); /*1バイト書き込む*/
    }
  en = getETime();

  fclose (fpin);
  fclose (fpout);

  printf("Elapsed Time: %.6f\n", en - st);
}
