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
  //YOUR CODE GOES HERE
  if(argc<2||argc>3){
    perror("Invalid argc\n");
      return EXIT_FAILURE;
    }

  FILE *f=fopen(argv[1],"r");
  if(f==NULL){
    perror("Invalid file\n");
    return EXIT_FAILURE;
    }

  size_t n_hands;
  future_cards_t fc;
  fc.decks=malloc(sizeof(deck_t));
  fc.decks[0].cards=NULL;
  fc.decks[0].n_cards=0;
  fc.n_decks=1;

  deck_t** input=read_input(f,&n_hands,&fc);
  deck_t* rem_deck=build_remaining_deck(input,n_hands);
  unsigned* win=calloc((n_hands+1),sizeof(*win));
  unsigned int num_trials;
  if(argc==3){
      num_trials=atoi(argv[2]);
    }
  else{
      num_trials=10000;
    }
  for(size_t i=0;i<num_trials;i++){
      shuffle(rem_deck);
      future_cards_from_deck(rem_deck,&fc);
      int decide;
      size_t index=0;
      size_t indexi=0;
      for(size_t j=1;j<n_hands;j++){
	  decide=compare_hands(input[indexi],input[j]);
	  if(decide<0){
	      indexi=j;
	      index=j;
	    }
	  else if(decide>0){
	      index=indexi;
	    }
	  else{
	      index=n_hands;
	    }
	}
      win[index]++;
    }
  
  for(size_t k=0;k<n_hands;k++){
      printf("Hand %zu won %u / %u times (%.2f%%)\n",k,win[k],num_trials,(double)win[k]/(double)num_trials*100);
    }
  printf("And there were %u ties\n",win[n_hands]);
  
  for(int i=0;i<fc.n_decks;i++){
      free(fc.decks[i].cards);
    }
  free(fc.decks);

  for(int i=0;i<n_hands;i++){
    free_deck(input[i]);
  }
  free(input);
  free_deck(rem_deck);
  free(win);
  if(fclose(f)!=0){
    perror("Unable to close file\n");
  }
  return EXIT_SUCCESS;
}
 
