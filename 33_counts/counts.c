#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *structure=(counts_t*)malloc(sizeof(counts_t));
  structure->size=0;
  structure->counts=malloc(100*sizeof(*structure->counts));
  structure->unknown=malloc(100*sizeof(*structure->unknown));
  structure->unknown->count=0;
return structure;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  int flag=0;
  if(name==NULL){
    if(c->unknown->count > 0){
    c->unknown->count++;
    }
    else {
      c->unknown->count=0;
      c->unknown->count++;
    }
    strcpy(c->unknown->s, "<unknown>");
  }
  else{
    for(size_t i=0;i<c->size;i++){
      if(strcmp(c->counts[i].s, name) == 0){
	c->counts[i].count++;
	flag=1;
      }
    }
  
    if(flag==0){
      c->counts[c->size].count=0;
      c->counts[c->size].count++;
      strcpy(c->counts[c->size].s, name);
      c->size++;
    }
    }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i=0;i<c->size;i++){
    fprintf(outFile,"%s: %ld\n",c->counts[i].s,c->counts[i].count);
  }
  if(c->unknown->count != 0){
    fprintf(outFile,"%s : %ld\n",c->unknown->s,c->unknown->count);
    }
}

void freeCounts(counts_t * c) {
  //WRITE ME
    free(c->counts);
    free(c->unknown);
  free(c);
}
