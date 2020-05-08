#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n<=0) return EXIT_FAILURE;
  if (array==NULL) return EXIT_FAILURE;
  int maxCount1=1;
  int maxCount2=1;
  int temp;
  for (int i=0; i<n; i++){
    if (array[i]<array[i+1]) {
      maxCount1++;
	  } else {
      if (maxCount1>maxCount2){
	temp=maxCount2;
	maxCount2=maxCount1;
	maxCount1=temp;
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
