#include <stdio.h>

/* QUIZ 8-2_2
 *  ��¤�� profile������ hobby[2]��scanf��ɸ�����Ϥ���
 *  ������ä��ͤ��������ƽ��Ϥ��褦�Ȥ��Ƥ��롣
 *  ��¤�Τˤ�name��age�����ꡢscanf�ǤϤ��ä���tmp�Ȥ���ʸ��������
 *  ���������Ƥ��� hobby[i].name=tmp�Ȥ��Ƥ��롣ǯ���Ʊ�ͤˤ��Ƥ��롣
 *��2̾ʬ�Υץ�ե����뤬�Ф�褦�ˤ������Τ�������̾��̾�����ɤ����
 *  Ʊ���ˤʤäƤ��ޤ����ʤ�����
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

