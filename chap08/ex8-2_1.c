#include <stdio.h>

/* QUIZ 8-2_1
 *  名前を入力してもらい、Hello <名前>と出したいが、
 *  Bus Error になってしまう。なぜか。
 */

int main(){
  char name[20];

  printf("What is your name?\n");
  scanf("%s",name);
  printf("Hello %s\n", name);


}

