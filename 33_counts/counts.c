#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * count = malloc(sizeof(* count));
  count->array = NULL;
  // // count->array = malloc(sizeof(* count->array));
  count->array_len=0;
  count->unknown_count=0;
  return count;
}

void addCount(counts_t * c, const char * name) {
  if (name==NULL){
    c->unknown_count++;
    return;
  }
  if (name!=NULL){
  int len = c->array_len;
  char * entry = strdup(name);
  c->array = realloc(c->array, (c->array_len+1)*sizeof(* c->array));
  for (int i=0; i<c->array_len; i++){
    if (strcmp(c->array[i]->value, name)==0){
      //     printf("same %s\n",entry);
      c->array[i]->count++;
      free(entry);
      return;
    }
  }
  c->array[len]=malloc(sizeof(* c->array[len]));
  c->array[len]->value=entry;
  c->array[len]->count=1;
  c->array_len++;
  }

  return;
  
}

void printCounts(counts_t * c, FILE * outFile) {
  for (int i=0; i<c->array_len; i++){
    fprintf(outFile, "%s: %d\n", c->array[i]->value, c->array[i]->count);
  }
  if (c->unknown_count>0){
    fprintf(outFile, "<unknown> : %d\n", c->unknown_count);
}
}

void freeCounts(counts_t * c) {
  for (int i=0; i<c->array_len; i++){
    free(c->array[i]->value);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}
