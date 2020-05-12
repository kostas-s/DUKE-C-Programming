#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void printMatrix(char matrix[10][10]){
    for(int y=0; y<10; y++){
      for(int x=0; x<10; x++){
	fprintf(stdout, "%c",matrix[y][x]);
	if (x==9) printf("\n");
      }
    }
}

void rotate(char matrix[10][10]){
  char rotMat[10][10];
  int p2;
  // create a second matrix with intended rotation
  for (int rotRow=0; rotRow<10; rotRow++){
  p2=0;
  for (int p1=9; p1>=0; p1--){
    rotMat[rotRow][p2]=matrix[p1][rotRow];
    p2++;
  }
  }
  // copy from rotated matrix to the one passed in the function
   for (int row=0; row<10; row++){
   for (int col=0; col<10; col++){
     matrix[row][col] = rotMat[row][col];
   }
  }
  printMatrix(matrix);
}


int main(int argc, char ** argv){
  if (argc!=2) {
    fprintf(stderr, "Usage: enter file to rotate as argument\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f==NULL){
    fprintf(stderr, "File does not exist\n");
    return EXIT_FAILURE;
  }

  // TRANSFER FILE TO ARRAY
  
  char matrix[10][10];
  int c;
  int y=0;
  int x=0;
  while ((c = fgetc(f))!= EOF){
    if (y==10){
      fprintf(stderr, "Matrix has more than 10 lines\n");
      return EXIT_FAILURE;
    }
    if (c==10 && x<10){
      fprintf(stderr, "Line %d is shorter than 10 characters\n",y);
      return EXIT_FAILURE;
    }
    if (x==10){
      if (c==10){
      y++;
      x=0;
      continue;
    }else{
	fprintf(stderr, "Line %d is longer than 10 characters\n",y);
      return EXIT_FAILURE;
    }
    }
    matrix[y][x]=c;
    x++;
  }
  if (x!=0 || y!=10){
    fprintf(stderr, "Matrix is of wrong size (should be 10x10)\n");
    return EXIT_FAILURE;
      }
  rotate(matrix);
  

  if (fclose(f) != 0){
    perror("Failed to close the input file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
