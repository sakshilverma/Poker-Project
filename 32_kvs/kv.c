#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

char *splitLine(char *line){
  char *value=strchr(line,'=');
  *value='\0';
  value++;
  value[strlen(value) -1]='\0';
  return value;
}

kvarray_t * readKVs(const char * fname) {
//WRITE ME
  FILE *f=fopen(fname, "r");
  if(f==NULL){
    perror("Invalid file\n");
  }
  kvarray_t *kvarray=malloc(sizeof(*kvarray));
  size_t numPairs=0;
  char *line=NULL;
  size_t sz;
  while(getline(&line,&sz,f) != -1){
    if(line[0]=='\n'){
      continue;
    }
    kvarray->pair=realloc(kvarray->pair, ((numPairs+1) * sizeof(*kvarray->pair)));
    kvarray->pair[numPairs]=malloc(sizeof(*kvarray->pair[numPairs]));
    kvarray->pair[numPairs]->value=malloc(sizeof(*kvarray->pair[numPairs]->value));
    kvarray->pair[numPairs]->value=splitLine(line);
    kvarray->pair[numPairs]->key=malloc(sizeof(*kvarray->pair[numPairs]->key));    
    kvarray->pair[numPairs]->key=line;
    numPairs++;
    line=NULL;
  }
  free(line);
  kvarray->numPairs=numPairs;
  fclose(f);
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    free(pairs->pair[i]->key);
    free(pairs->pair[i]->value);
    free(pairs->pair[i]);
    
  }
  free(pairs->pair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    printf("key = '%s' value = '%s'\n", pairs->pair[i]->key,pairs->pair[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    if(pairs->pair[i]->key==key){
      return pairs->pair[i]->value;
    }
  }
    return NULL;
 
}
