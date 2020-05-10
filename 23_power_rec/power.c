#include <stdio.h>
#include <stdlib.h>
  
unsigned power(unsigned x, unsigned y){
  if (x==0 && y==0) return 1;
  //  printf("Entered power with x=%u, y=%u \n",x,y);
  if (y<=0){
    return 1;
  }else{
    return power(x, y-1)*x;  
  }
}

//int main(){
//  printf("Result is:%u\n", power(5,0));
//return EXIT_SUCCESS;
//}
  
