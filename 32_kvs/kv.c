#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include <assert.h>
#include <ctype.h>

kvpair_t * readKV(FILE *f) {
  size_t sz=0;
  char * line=NULL;
  kvpair_t * readArray=NULL;
  //  malloc(sizeof(readArray));

  assert(f!=NULL);
  //char * key =malloc(sizeof(char*)*sz);
  //char * value = malloc(sizeof(char*)*sz);
  char * key=NULL;
  char * value=NULL;
 
  if (getline(&line, &sz, f)!=EOF){
    for (size_t i=0; i<sz; i++){
      if (line[i]==61) {
	int x=0;
	for (size_t j=i+1; j<sz; j++, x++){
	  if (line[j]=='\n' || line[j]=='\0'){
	    break;
	  }
	  value=realloc(value, (x+1)*sizeof(value));
	  value[x]=line[j];
	}
	break;
      }
      key = realloc(key, (i+1)*sizeof(key));
      key[i]=line[i];
    }
    readArray=realloc(readArray, sz*sizeof(readArray));
    readArray->key=key;
    readArray->value=value;
  }else{
    free(line);
    //free(key);
    //free(value);
    return 0;
  }
  free(line);
  return readArray;
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
    free(pairs->list[i]->value);
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
    if (strcmp(pairs->list[i]->key,key)==0){
      return pairs->list[i]->value;
    }
  }
  return NULL;
}
