#include <stdio.h>

/* QUIZ 8-2_1
 *  ̾�������Ϥ��Ƥ�餤��Hello <̾��>�ȽФ���������
 *  Bus Error �ˤʤäƤ��ޤ����ʤ�����
 */

int main(){
  char name[20];

  printf("What is your name?\n");
  scanf("%s",name);
  printf("Hello %s\n", name);


}

