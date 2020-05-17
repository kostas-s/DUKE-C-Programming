#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"



int main(int argc, char ** argv) {
  if (argc > 3 || argc < 2) {
    fprintf(stderr, "Usage: enter hand and number of trials\n");
    return EXIT_FAILURE;
  }
  
  // if trial number not entered you should use 10000 as default value
  unsigned trials = 10000;
  if (argc==3){
    trials = atoi(argv[2]);
  }

  FILE * f = fopen(argv[1], "r");
  if (f==NULL){
    fprintf(stderr, "File not found\n");
    return EXIT_FAILURE;
  }
  
  

  return EXIT_SUCCESS;
}
