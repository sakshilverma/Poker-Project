#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE *f=fopen(filename, "r");
  if(f==NULL){
    perror("Invalid File\n");
return NULL;
  }
  counts_t *c=createCounts();
 char *key;
  size_t sz;
  char *line=NULL;
  int flag=0;
  while(getline(&line,&sz,f) != -1){
    if(line[0]=='\n'){
      continue;
    }
    flag=0;
    for(int i=0;i<kvPairs->numPairs;i++){
      if(strcmp(line,kvPairs->pair[i]->key) == 0){
	flag=1;
	strcpy(key,kvPairs->pair[i]->value);
	break;
      }
    }
    if(flag==0){
      key=NULL;
    }
    addCount(c,key);
}
  free(line);
  fclose(f);
  return c;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<=1){
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t *kv=readKVs(argv[1]);  
 
  //count from 2 to argc (call the number you count i)
  for(int i=2;i<argc;i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c=countFile(argv[i], kv); 
    if(c==NULL){
      return EXIT_FAILURE;
    } 
    //compute the output file name from argv[i] (call this outName)
    char *outName=computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE *f=fopen(outName, "w");
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    fclose(f);
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }


 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
