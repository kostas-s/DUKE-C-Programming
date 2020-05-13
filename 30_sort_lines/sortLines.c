#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printData(char ** sortedData, size_t count){
  for (size_t i=0; i<count; i++){
    printf("%s", sortedData[i]);
    free(sortedData[i]);
  }
}


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.


int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}


//This function will sort and print data (whose length is count).


void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}


void loadData(FILE * f){
  char ** array=NULL;
  char * line=NULL;
  size_t sz=0;
  size_t i=0;
  while (getline(&line, &sz, f)>=0){
    array=realloc(array, sz*sizeof(*array)+sizeof(*array));
    array[i]=line;
    // printf("line is:%s",line);
    //printf("array%zu is:%s\n",i,array[i]);
    line = NULL;
    i++;
  }
  free(line);
  sortData(array, i);
  printData(array, i);
  free(array);
}


int main(int argc, char ** argv) {

  if (argc==1){
    loadData(stdin);
    }
  
  if (argc>1){
    for (int i=1; i<argc; i++){
      FILE * f = fopen(argv[i], "r");
      if (f==NULL) {
	fprintf(stderr, "File not found\n");
	return EXIT_FAILURE;
      }
      loadData(f);
    if (fclose(f)!=0) {
      fprintf(stderr, "File could not close properly\n");
      return EXIT_FAILURE;
    }
  }
  }
  
  return EXIT_SUCCESS;
}
