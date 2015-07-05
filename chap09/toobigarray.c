#include <stdio.h>

int main(){
  int a[1500000];
  int b[1000000];
  int c = 0;
  printf("&a=%x,&b=%x,&i=%x\n",a,b,&c);
}
