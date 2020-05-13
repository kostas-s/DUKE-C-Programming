#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  char * outName=malloc(strlen(inputName)*sizeof(outName)+7*sizeof(outName));
  strcpy(outName, inputName);
  return strcat(outName, ".counts");
}
