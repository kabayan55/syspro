#include <stdio.h>
#include <stdlib.h>

/*大域変数*/
char *gen_string();  /*初期値がない*/

int main(){
  char *str;    
  char array[8];　　
		  int i;　　
			  
			  /*step1*/ 			  
			  printf("-----variables-----\n");
  printf("i                                   :%8x\n",&i);  
  printf("-----arrays-----\n");
  printf("*gen_string                         :%8x\n",&gen_string);
  printf("array[8]                            :%8x\n",array[8]);
  printf("str                            :%8x\n",*str);
  printf("-----functions-----\n");
  printf("printf                             :%8x\n",printf);
  printf("srand                             :%8x\n",srand);
  printf("rand                             :%8x\n",rand);
  printf("gen_string                             :%8x\n",gen_string);
  printf("main                                :%8x\n",main);
  
  
  /*step2*/
  printf("-----variables-----\n");
  printf("-----arrays-----\n");
  printf("*gen_string                         :%8x\n",&gen_string);
 printf("*str                                :%8x\n",&str);
 printf("-----functions-----\n");
 printf("printf                             :%8x\n",printf);
 printf("srand                             :%8x\n",srand);
 printf("rand                             :%8x\n",rand);
  printf("gen_string                             :%8x\n",gen_string);
  printf("main                                :%8x\n",main);
 
}
