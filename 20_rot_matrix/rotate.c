#include <stdio.h>
#include <stdlib.h>

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

}
