#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

// a function to identify and return the most common character
int find_common_char(FILE * f){
  int max_chars=0;
  int max_chars_idx=0;
  int letters[26] = {0};
  int c;
  while (( c = fgetc(f)) != EOF){
    if (isalpha(c)){
      c = tolower(c);
      letters[c-97]++;
      //   printf("%c",c);
    }
  }
  for (int i=0; i<=25; i++){
    if (letters[i]>max_chars) {
      max_chars=letters[i];
      max_chars_idx=i;
  }
  }
  return max_chars_idx+97;
}

/* //Made for my own fun and testing purposes, working good. */
/* void decrypt(FILE * f, int key){ */
/*   //  printf("DECRYPTED FILE BELOW:\n"); */
/*   int c; */
/*   while (( c = fgetc(f)) != EOF){ */
/*     if (isalpha(c)){ */
/*       c=tolower(c); */
/*       c -= 'a'; */
/*       c -= key; */
/*       if (c<0) c+=26; */
/*       c += 'a'; */
/*       //  printf("%c",c); */
/*     }else{ */
/*       //    printf("%c",c); */
/*   } */
/* } */
/*   // printf("\n"); */
/* } */

int main(int argc, char ** argv){
  int most_common_ascii;
  if (argc!=2) {
    fprintf(stderr, "Usage: enter text to decypt as argument\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f==NULL) {
    fprintf(stderr, "Cant open specified file\n");
    return EXIT_FAILURE;
  }
  most_common_ascii = find_common_char(f);
  //  printf("===%c is the most common letter===\n",most_common_ascii);
  //int key = most_common_ascii - 101;
  int key = most_common_ascii - 97;
  // To use my own decrypt, remove next 2 statements, subtract by 101 for key and uncomment rewind/decrypt
  key+=22;
  key%=26;
  
  assert(key>=0 && key < 26);
  fprintf(stdout, "%d\n",key);

  // rewind(f);
  // decrypt(f, key);

  if (fclose(f) != 0){
    perror("Failed to close the input file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
