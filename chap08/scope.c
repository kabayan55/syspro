#include <stdio.h>

int z;
int main(){
	int i;
	z=0;
	for(i=0;i<5;i++){
	  z=z+1;
	  func(i);
	
	}
}

int func(int a){
  static int x=0;
  int y=0;
  x=x+1;
  y=y+1;
  z=z+1;
  printf("x=%d\t y=%d\t z=%d\n",x,y,z);
  
}
