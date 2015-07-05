#include <stdio.h>

/* QUIZ ex8-2_4
 *  atoi関数を自作してみた。第一引数に文字列を入れると戻り値に
 *  数値がかえってくる。ただし０〜９以外の文字が含まれていたら、
 *  その文字のアドレスを第2引数に指定されたポインタ変数に代入する
 *  ようにしたい。このプログラムの結果では
 *    num=123 str=XY
 *  と出てくるはずであった。がstrの値が正しく表示されない。なぜか？
 *
 */

int myatoi(char *,char *);

int main(){
  char *str="123XY";
  char *cur;
  int a;
  a = myatoi(str,cur);
  printf("num=%d str=%s\n",a,cur);
}

/*  myatoi(char *str,char *p)
 *    strに文字列を入れると10進数の数字に変換する
 *    pは10進数の数字ではない文字のアドレスが入る
 */
int myatoi(char *str,char *p){
  p=str;
  int num=0;
  while(*p!='\0'){
    if((*p)<'0' || (*p)>'9'){
      break;
    }
    num=num*10+((*p)-'0');
    p++;
  }
  return num;
}
