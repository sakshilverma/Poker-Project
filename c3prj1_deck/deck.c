#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  for(int i=0;i<(*hand).n_cards;i++)
    { card_t c = *((*hand).cards)[i];
      print_card(c);
  printf(" ");
}}

int deck_contains(deck_t * d, card_t c) {
    for(int i=0;i<d->n_cards;i++)
      if(d->cards[i]->value==c.value && d->cards[i]->suit==c.suit)
    {return 1;
    }
    
  return 0;
}

void shuffle(deck_t * d){
  size_t n = d->n_cards;
  card_t ** ptc = d->cards;
  for(int i = n-1; i>0; i--){

    int k = random()%n;

    card_t ** ptc1 = ptc +n -1 -i;
    card_t ** ptc2 = ptc + k;
    card_t * temp = *ptc1;
    *ptc1 = *ptc2;
    *ptc2 = temp;
  }
  
}

void assert_full_deck(deck_t * d) {
  for(int i=0;i<d->n_cards;i++)
    {
      for(int j=i+1;j<d->n_cards;j++)
	{ assert(d->cards[i]!=d->cards[j]);
	}
    }
}
