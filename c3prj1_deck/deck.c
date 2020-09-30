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
  card_t temp;
  int y = random()%(d->n_cards);
  for(int i=0;i<((d->n_cards)/2)+2;i++)
   {
temp=*(d->cards[y]);
 *(d->cards)[y]=*(d->cards)[i];
 *(d->cards)[i]=temp;
}}

void assert_full_deck(deck_t * d) {
  for(int i=0;i<d->n_cards;i++)
    {
      for(int j=i+1;j<d->n_cards;j++)
	{ assert(d->cards[i]!=d->cards[j]);
	}
    }
}

void add_card_to(deck_t * deck, card_t c){
  deck->cards=realloc(deck->cards, (deck->n_cards+1)*sizeof(deck->cards));
  card_t *card=malloc(sizeof(*card));
  *card=c;
  deck->cards[deck->n_cards]=card;
 deck->n_cards++;
  // deck->cards[n_cards-1]->value=c->value;
  // deck->cards[n_cards-1]->suit=c->suit;
}

card_t * add_empty_card(deck_t * deck){
  card_t *c=malloc(sizeof(*c));
  c->value=0;
  c->suit=0;
  //add_card_to(deck,c);
  deck->cards=realloc(deck->cards, (deck->n_cards+1)*sizeof(deck->cards));
  deck->cards[deck->n_cards]=c;
  deck->n_cards++;
  return c;
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t *d=malloc(sizeof(*d));
  d->cards=malloc(sizeof(d->cards));

  int n=0;
  for(int i=0;i<52;i++){
    card_t c=card_from_num(i);
    if(!deck_contains(excluded_cards,c)){
      add_card_to(d,c);
      n++;
    }
  }
  d->n_cards=n;
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t * d=malloc(sizeof(*d));
  d->cards=malloc(sizeof(d->cards));
 int n=0;
  for(int i=0;i<n_hands;i++){
    for(int j=0;j<hands[i]->n_cards;j++){
      card_t *c=malloc(sizeof(*c));
      *c=*hands[i]->cards[j];
      add_card_to(d,*c);
      n++;
    }
  }

  d->n_cards=n;

  deck_t *r_deck=make_deck_exclude(d);

  return r_deck;
}

void free_deck(deck_t * d){
  for(int i=0;i<d->n_cards;i++){
    free(d->cards[i]);
  }
  free(d->cards);
  free(d);
} 
   
