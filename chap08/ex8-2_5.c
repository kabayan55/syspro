#include <stdio.h>
#include <stdlib.h>

/* QUIZ 8-2_5
   リスト構造を実装してみた。
　　リスト構造へのノードの追加をするためにpush関数を用意した。
　　第一引数はリストの最後尾ノードのポインタ，
　　第二引数はノードに入れるべき値である。
　　0から9までの数値の入ったノードをリストにしているので
   (0,-)->(1,-)->(2,-)->(3,-)->...->(9,NULL)
   となるはずである。（ちなみに (0,-)->(1,-)というのは最初のノードのnext
   で次のノードを参照しているという意味。）
　　しかし、リストは全く形成されない。なぜか。
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
