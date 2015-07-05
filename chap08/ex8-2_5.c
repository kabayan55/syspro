#include <stdio.h>
#include <stdlib.h>

/* QUIZ 8-2_5
   �ꥹ�ȹ�¤��������Ƥߤ���
�����ꥹ�ȹ�¤�ؤΥΡ��ɤ��ɲä򤹤뤿���push�ؿ����Ѱդ�����
�����������ϥꥹ�ȤκǸ����Ρ��ɤΥݥ��󥿡�
������������ϥΡ��ɤ������٤��ͤǤ��롣
����0����9�ޤǤο��ͤ����ä��Ρ��ɤ�ꥹ�Ȥˤ��Ƥ���Τ�
   (0,-)->(1,-)->(2,-)->(3,-)->...->(9,NULL)
   �Ȥʤ�Ϥ��Ǥ��롣�ʤ��ʤߤ� (0,-)->(1,-)�Ȥ����ΤϺǽ�ΥΡ��ɤ�next
   �Ǽ��ΥΡ��ɤ򻲾Ȥ��Ƥ���Ȥ�����̣����
�������������ꥹ�Ȥ�������������ʤ����ʤ�����
 */

typedef struct numlist{
  int value;
  struct numlist *next;
} numlist;

void push(numlist *prev,int num){
  numlist *node = (numlist *)malloc(sizeof(struct numlist));
  node->value=num;
  node->next=NULL;
  if(prev==NULL){
    prev=node;
  }else{
    prev->next=node;
  }
  
}

int main(){
  numlist *head=NULL;
  numlist *tail=NULL;
  int i;

  for(i=0;i<10;i++){
    push(tail,i);
    if(i==0){head==tail;}
  }

  i=0;
  while(head!=NULL){
    printf("[%d] value=%d\n",i,head->value);
    head=head->next;
    i++;
  }


}
