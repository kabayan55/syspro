#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *gen_string();

int main(){
  char *str;

  str = gen_string();
  /* step 2 */
  printf("input any key\n");
  getchar();
  printf("generated string\t%s\n",str);

  /*step2*/
  printf("-----variables-----\n");
  printf("-----arrays-----\n");
  printf("*gen_string                         :%8x\n",&gen_string);
  printf("*str                                :%8x\n",&str);
  printf("-----functions-----\n");
  printf("printf                              :%8x\n",printf);
  printf("srand                               :%8x\n",srand);
  printf("rand                                :%8x\n",rand);
  printf("gen_string                          :%8x\n",gen_string);
  printf("main                                :%8x\n",main);
 
}

char *
gen_string(){
  char *array;
  int i;
  array = (char*) malloc (sizeof(char) * 8);
  srand(time(NULL));
  for(i=0; i<8; i++){
    array[i] = rand () % ('z' - 'A') + 'A';
  }
  /* step 1 */


/*step1*/ 			  
printf("-----variables-----\n");
printf("i                                   :%8x\n",&i);  
printf("-----arrays-----\n");
printf("*gen_string                         :%8x\n",&gen_string);
printf("array                               :%8x\n",&array);
printf("-----functions-----\n");
printf("printf                              :%8x\n",printf);
printf("srand                               :%8x\n",srand);
printf("rand                                :%8x\n",rand);
printf("gen_string                          :%8x\n",gen_string);
printf("main                                :%8x\n",main);


  return array;
}


