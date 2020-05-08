#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n<0) return EXIT_FAILURE;
  if (array==NULL) return EXIT_FAILURE;
  if (n==0) return 0;
  size_t maxCount1=1;
  size_t maxCount2=1;
  //  size_t temp;
  for (int i=1; i<n; i++){
    if (array[i]>array[i-1]) {
      maxCount1++;
	  } else {
      if (maxCount1>maxCount2){
	//	temp=maxCount2;
	maxCount2=maxCount1;
	maxCount1=1;
      }else{
	maxCount1=1;
      }
  }
  }
  if (maxCount1>=maxCount2){
    return maxCount1;
  }else{
    return maxCount2;
  }
}
