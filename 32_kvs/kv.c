#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include <assert.h>
#include <ctype.h>

kvpair_t * readKV(FILE *f) {
  char *line = NULL;
  size_t sz = 0;
				 //Get whole line and store it into "line"
  if (getline(&line, &sz, f)==EOF) {
    free(line);                  //free line if we've reached EOF
    return NULL;
  }
				 //Find first occurrence to = and set ptr to point there
  char * ptr1 = strchr(line, '=');
  if (ptr1 == NULL) return NULL;

  char * ptr2 = strchr(line, '\n');
  * ptr1 = '\0';                 //Create bounds of key and value, line will point to key and ptr1 at '\0' - previously '='
  * ptr2 = '\0';

  kvpair_t * returnPair=malloc(sizeof(*returnPair));
  returnPair->key = line;
  ptr1++;
  returnPair->value = ptr1;
  return returnPair;
}

kvarray_t * readKVs(const char * fname) {
  FILE * f = fopen(fname, "r");
  if (f==NULL){
    fprintf(stderr, "File not found");
    return NULL;
  }
  int line_num=0;
  kvarray_t * answerArray = malloc(sizeof(* answerArray));
  kvpair_t * pair = NULL;
  answerArray->list_len=0;
  answerArray->list=NULL;
 
  while ((pair = readKV(f))!=NULL){
    answerArray->list = realloc(answerArray->list, (line_num+1)*sizeof(* answerArray->list));
    answerArray->list[line_num] = pair;
    line_num++;
        
}
  answerArray->list_len=line_num;
  assert(fclose(f)==0);
  free(pair);
  return answerArray;
}
void freeKVs(kvarray_t * pairs) {
  for (int i=0; i<pairs->list_len; i++){
    free(pairs->list[i]->key);
    //free(pairs->list[i]->value); Commented out, getting invalid frees on Valgrind
    free(pairs->list[i]);
  }
  free(pairs->list);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  int num = pairs->list_len;
  kvpair_t ** ptr = pairs->list;
  for (int i=0; i<num; i++){
    printf("key = '%s' value = '%s'\n",ptr[i]->key, ptr[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for (int i=0; i<pairs->list_len; i++){
    //    printf("in forloop with key: %s, comparing to %s\n", key, pairs->list[i]->key);    
    if (strcmp(pairs->list[i]->key, key)==0){
      // printf("FOUND IT");
      return pairs->list[i]->value;
    }
  }
  return NULL;
}
