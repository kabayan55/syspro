#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

/*get ETime 現在時刻を求める関数*/
double
getETime()
{
  struct timeval tv;
  gettimeofday (&tv,NULL);
  return tv.tv_sec + (double) tv.tv_usec * 1e-6;
}

int
main(int argc,char *argv[])
{
  int fdin, fdout;
  char c;
  double st, en;

  if(argc != 3)
    {
      fprintf(stderr, "Usage: ./copy_lowio<コピー元><コピー先>");
      exit(EXIT_FAILURE);
    }
  /*入力用ファイルを開く*/
  if((fdin = open (argv[1],O_RDONLY)) <0)
    {
      perror(argv[1]);
      exit(EXIT_FAILURE);
    }
  /*出力用ファイルを開く*/
  if((fdout = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666)) <0)
    {
      perror(argv[2]);
      exit(EXIT_FAILURE);
    }
  /*1バイトずつコピーする*/
  st = getETime();
  while(read (fdin, &c, 1) == 1)
    {                          /*1バイト読込む*/
      write(fdout, &c,1);      /*1バイト書き込む*/
    }
  en = getETime();
  close(fdin);
  close(fdout);

  printf("Elapsed Time: %.6f\n", en - st);
} 
