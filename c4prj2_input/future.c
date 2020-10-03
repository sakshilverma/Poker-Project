#include <stdio.h>
#include <stdlib.h>
#include "future.h"
#include "cards.h"
#include "deck.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
 if(index+1 >= fc->n_decks){
	fc->decks=realloc(fc->decks,(index + 1)*sizeof(*fc->decks));
	for (size_t i=fc->n_decks;i<index+1;i++){
	    fc->decks[i].cards=NULL;
	    fc->decks[i].n_cards=0;
	  }
	fc->n_decks=index+1;
      }
 else {
   fc->decks[index].cards=realloc(fc->decks[index].cards,(fc->decks[index].n_cards+1)*sizeof(*fc->decks[index].cards));
    fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
    fc->decks[index].n_cards++;
 }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  if(!fc||!deck)
    {
      fprintf(stderr,"\nInvalid fc");
      exit(EXIT_FAILURE);
    }
  if(deck->n_cards < fc->n_decks){
    perror("Not enough cards in deck\n");
    exit(EXIT_FAILURE);
  }

  for(size_t i=0;i<fc->n_decks;i++){
    if(fc->decks[i].n_cards==0){
      continue;
    }
    for(size_t j=0;j<fc->decks[i].n_cards;j++){
      if(!deck->cards||!fc->decks[i].cards)
	{
	  fprintf(stderr,"\nInvalid deck");
	  exit(EXIT_FAILURE);
	}
      fc->decks[i].cards[j]->value=deck->cards[i]->value;
      fc->decks[i].cards[j]->suit=deck->cards[i]->suit;}
  }
}
