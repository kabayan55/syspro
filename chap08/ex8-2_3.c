#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * QUIZ 8-2_3
 * ex8-1.cの変形である。
 * mainでポインタ変数strを用意し、その値はgen_stringの中で
 * mallocで確保し値を入れてもらっている。
 * ランダムに８文字を生成してもらっているはずなのだが
 * printで文字が表示されない。なぜか。
 */

void gen_string(char *,int);

int main(){
  char *str;
  gen_string(str,8);
  printf("%s\n",str);

}

void gen_string(char *str,int n){
  int i;
  srand(time(NULL));
  str=(char *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    str[i]=rand()%('z'-'A')+'A';
  }
}
