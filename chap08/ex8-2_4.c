#include <stdio.h>

/* QUIZ ex8-2_4
 *  atoi�ؿ��򼫺�Ƥߤ�����������ʸ���������������ͤ�
 *  ���ͤ������äƤ��롣�������������ʳ���ʸ�����ޤޤ�Ƥ����顢
 *  ����ʸ���Υ��ɥ쥹����2�����˻��ꤵ�줿�ݥ����ѿ�����������
 *  �褦�ˤ����������Υץ����η�̤Ǥ�
 *    num=123 str=XY
 *  �ȽФƤ���Ϥ��Ǥ��ä�����str���ͤ�������ɽ������ʤ����ʤ�����
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
 *    str��ʸ�����������10�ʿ��ο������Ѵ�����
 *    p��10�ʿ��ο����ǤϤʤ�ʸ���Υ��ɥ쥹������
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
