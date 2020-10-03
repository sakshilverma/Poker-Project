#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "input.h"
#include <ctype.h>

deck_t *hand_from_string(const char *str, future_cards_t *fc){
  deck_t *hand=malloc(sizeof(*hand));
  hand->n_cards=0;
  hand->cards=malloc(sizeof(*hand->cards));
  char *rem=strchr(str, '\n');
  if(rem!=NULL){
      *rem='\0';
    }
  while(*str!='\0'){
      if(*str=='?'){
	  str++;
	  char *tmp=malloc(sizeof(*tmp));
	  size_t s=0;
	  while(*str != ' ' && *str != '\0'){
	      tmp=realloc(tmp,(1 + s)*sizeof(*tmp));
	      tmp[s]=*str;
	      s++;
	      str++;
	    }
	  tmp=realloc(tmp,(1 + s)*sizeof(*tmp));
	  tmp[s]='\0';
	  int index=atoi(tmp);
	  free(tmp);
	  card_t *emp=add_empty_card(hand);
	  add_future_card(fc,index,emp);
	}
      else if(*str == ' '){
	  str++;
	}
      else{
	  add_card_to(hand,card_from_letters(*str, str[1]));
	  str+=2;
	}
    }
  return hand;
}

deck_t **read_input(FILE *f, size_t *n_hands, future_cards_t *fc){
  deck_t **result=malloc(sizeof(*result));
  *n_hands=0;
  char *line=NULL;
  size_t sz;
  while(getline(&line, &sz, f) > 1){
      deck_t *hand=hand_from_string(line, fc);
      if(hand->n_cards < 5){
	  perror("One of the hands in your input file has less than 5 cards in it\n");
	  return NULL;
	}

      result=realloc(result,(1 + *n_hands)*sizeof(*result));
      result[*n_hands]=hand;
      (*n_hands)++;
    }
  free(line);
  return result;
}
