#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"
#include <assert.h>

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE *f = fopen(filename, "r");
  if (f==NULL){
    fprintf(stderr, "File specified not found");
    assert(f!=NULL);
    return NULL;
  }
  counts_t * count= createCounts();
  char * line=NULL;
  size_t sz=0;
  char * value = NULL;
  char * ptr1 = NULL;
  while (getline(&line, &sz, f)!=EOF){
    ptr1 = strchr(line, '\n');
    *ptr1='\0';
    value = lookupValue(kvPairs, line);
    addCount(count, value);
    // printf("did lookup of %s in kvPairs, found %s\n", line, value);
    //   free(line);
    }
  free(line);

  //  printKVs(kvPairs);
  //printf("%d", kvPairs->list_len);
  if(fclose(f)!=0){
    fprintf(stderr, "Unable to close countFile");
    return NULL;
  }
  return count;
}



int main(int argc, char ** argv) {

  if (argc<3){
    fprintf(stderr, "Usage: Enter at least 2 files as arguments\n");
    return EXIT_FAILURE;
  }

  kvarray_t * kv = readKVs(argv[1]);

  counts_t * c=NULL;
  char ext[] = ".counts";
  
  for (int i=2; i<argc; i++){
    // printf("OPENING FILE: %s\n", argv[i]);
    c = countFile(argv[i], kv);
    //printf("counts_t contains array len:%d unknown:%d\n",c->array_len,c->unknown_count);

    char * outName = malloc(sizeof(* outName)*(strlen(argv[i])+8));
    strcpy(outName, argv[i]);
    strcat(outName, ext);

    FILE * w = fopen(outName, "w");
    printCounts(c, w);
    
    if (fclose(w)!=0){
      fprintf(stderr, "Unable to close file after writing");
      return EXIT_FAILURE;
    }
    free(outName);
    freeCounts(c);
  }

  // freeCounts(c);
  freeKVs(kv);
  return EXIT_SUCCESS;
}
