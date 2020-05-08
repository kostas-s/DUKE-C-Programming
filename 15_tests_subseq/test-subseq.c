#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void){
  int array1[]= {1, 2, 3, 4, 3};
  int array2[]= {-1, -2, -3, 1};
  int array3[]= {-1, 1, -10, 10};
  int array4[]= {0, 0, 0};
  int array5[]= {0, 15, 15, 15};
  int array6[]= {};
  int array7[]= {-10, -1, 0, 1000, -2};
  int array8[]= {-3, -4, -5};
  size_t toprint;
  if (maxSeq(array8,3)!=1) {
    printf("failed on array8");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array1,5)!=4) {
    printf("failed on 1st");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array2,4)!=2) {
    toprint=maxSeq(array2,4);
    printf("failed on 2nd, ans returned:%zu", toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array3,4)!=2) {
    toprint=maxSeq(array3,4);
    printf("failed on 3rd, ans ret:%zu",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array4,3)!=1) {
    toprint=maxSeq(array4,3);
    printf("failed on 4th, ans ret:%zu",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array5,4)!=2) {
    toprint=maxSeq(array5,4);
    printf("failed on 5th, ans ret:%zu",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(NULL,0)!=0) {
    printf("failed null case");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6,1)!=1) {
    toprint=maxSeq(array6,1);
    printf("failed array6 expected%zu",toprint);
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array7,5)!=4) {
    printf("failed array7");
    exit(EXIT_FAILURE);
  }
  if (maxSeq(array6,0)!=0) {
    printf("failed array6 zero");
      exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
  
}
