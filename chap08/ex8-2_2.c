#include <stdio.h>

/* QUIZ 8-2_2
 *  構造体 profileの配列 hobby[2]にscanfで標準入力から
 *  受け取った値を代入して出力しようとしている。
 *  構造体にはnameとageがあり、scanfではいったんtmpという文字列配列
 *  に代入してから hobby[i].name=tmpとしている。年齢も同様にしている。
 *　2名分のプロファイルが出るようにしたいのだが、２名の名前がどちらも
 *  同じになってしまう。なぜか？
 */


typedef struct profile{
  char *name;
  int age;
} profile;

int main(){
  profile hobby[2];
  char tmp[64];
  int i,age;

  printf("Input profiles of 2 people.\n");
  for(i=0;i<2;i++){
    printf("[%d] Input his/her name.\n",i);
    scanf("%s",tmp);
    hobby[i].name=tmp;
    printf("[%d] Input his/her age.\n",i);
    scanf("%d",&age);
    hobby[i].age=age;
  }

  for(i=0;i<2;i++){
    printf("======%d======\n",i);
    printf(" name = %s\n",hobby[i].name);
    printf("  age = %d\n\n",hobby[i].age);
  }


}

