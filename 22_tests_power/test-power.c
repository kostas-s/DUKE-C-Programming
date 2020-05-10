#include <stdlib.h>
#include <stdio.h>

unsigned power (unsigned x, unsigned y);

unsigned powCorrect(unsigned x, unsigned y){
  unsigned result=1;
  while (y>0){
    result*=x;
    y--;
  }
  return result;
  
  }

int main(){
  if (power (1,0)!=1) exit(EXIT_FAILURE);
  if (power (-1,0)!=1) exit(EXIT_FAILURE);
  if (power (0,0)!=1) exit(EXIT_FAILURE);
  if (power (100,20)>1) exit(EXIT_FAILURE);
      //if (power (100,0)!=1) exit(EXIT_FAILURE);
      // if (power (100,0)!=1) exit(EXIT_FAILURE);
      // if (power (100,0)!=1) exit(EXIT_FAILURE);

  for (int i=1; i<300; i++){
     if (power (i,i/2)!=powCorrect(i,i/2)) {
      //      printf("%d to the %d:returned %u, my correct says it should be %u\n",i, i/2, power(i,i/2),powCorrect(i,i/2));
       exit(EXIT_FAILURE);
     }
  }
  return EXIT_SUCCESS;
}
