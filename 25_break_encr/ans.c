#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


size_t largestindx(int * array, size_t n){

  size_t indx=0;

  for (int i=1;i<n;i++){
    if (array[indx] < array[i]){
      indx = i;
    }
  }
  return indx;
}


int main(int argc, char ** argv) {


  if (argc != 2) {
    fprintf(stderr,"Invalid argc\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");

  if (f == NULL) {
    fprintf(stderr,"Could not open file\n");
    return EXIT_FAILURE;
  }

  int freq[26]={0};
  int c;
  int n = 0;

  while (((c = fgetc(f)) != EOF) &&  n<=100){

    if (isalpha(c)){
      freq[c-97] = freq[c-97] + 1;
      n++;
    }
  }

  size_t i = largestindx(freq, 26);

  int key = (i+22)%26;


  printf("%d\n",key);


  if (fclose(f) != 0) {
    fprintf(stderr,"Failed to close the input file!\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
