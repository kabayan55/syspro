#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * QUIZ 8-2_3
 * ex8-1.c���ѷ��Ǥ��롣
 * main�ǥݥ����ѿ�str���Ѱդ��������ͤ�gen_string�����
 * malloc�ǳ��ݤ��ͤ�����Ƥ��äƤ��롣
 * ������ˣ�ʸ�����������Ƥ��äƤ���Ϥ��ʤΤ���
 * print��ʸ����ɽ������ʤ����ʤ�����
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
