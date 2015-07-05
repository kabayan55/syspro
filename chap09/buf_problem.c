#include <stdio.h>

void func(){
  char buf[256];
  char c;
  int i=0;
  while((c=getchar())!=EOF){
    buf[i]=c;
    i++;
    if(i>=256){
      break;
    }
  }
  printf("buf=%s\n",buf);
}

int main(){
  func();
}
