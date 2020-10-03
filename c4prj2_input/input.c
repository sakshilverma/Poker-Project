#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "input.h"
/*
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
*/

deck_t** read_input(FILE* f,size_t* n_hands,future_cards_t* fc)
{
  deck_t** answer=NULL;
  size_t size;
  int len=0,i=0;
  char* line=NULL;
  while((len=getline(&line,&size,f))>=0)
    {
      if(line[len-1]=='\n')
	{
	  line[len-1]=0;
	  len--;
	}
      answer=realloc(answer,(i+1)*sizeof(*answer));
      answer[i]=malloc(sizeof(deck_t));
      answer[i]->cards=NULL;
      answer[i]->n_cards=0;
      int line_ind=0;;
      int count=0;
      while(line[line_ind])
	{
	  if(line[line_ind]==32)
	    {
	      line_ind++;
	      continue;
	    }
	  if(line[line_ind]=='?'&&isdigit(line[line_ind+1]))
	    {
	      line_ind++;
	      size_t index;
	      char num[5]={0};
	      int j;
	      for(j=0;line[line_ind];line_ind++)
		if(isdigit(line[line_ind]))
		  num[j++]=line[line_ind];
		else
		  break;
	      num[j]=0;
	      line_ind--;
	      index=strtoul(num,NULL,0);
	      if(index>=0)
		add_future_card(fc,index,add_empty_card(answer[i]));
	      else
		{
		  fprintf(stderr,"\nInvalid index");
		  exit(EXIT_FAILURE);
		}
	    }
	  else
	    {
	      char first=line[line_ind];
	      if(!isdigit(first)&&(first!='K'&&first!='A'&&first!='Q'&&first!='J'))
		{
		  fprintf(stderr,"\nInvalid input 1");
		  exit(EXIT_FAILURE);
		}
	      line_ind++;
	      if(line[line_ind]!='s'&&line[line_ind]!='h'&&line[line_ind]!='c'&&line[line_ind]!='d')
		{
		  fprintf(stderr,"\nInvalid input 2");
		  exit(EXIT_FAILURE);
		}
	      add_card_to(answer[i],card_from_letters(first,line[line_ind]));
	    }
	  line_ind++;
	  count++;
	}
      if(count<5)
	{
	  fprintf(stderr,"\nInvalid input 3");
	  exit(EXIT_FAILURE);
	}
      i++;
      //   free(line);
      // line;
    }
  free(line);
  *n_hands=i;
  return answer;
}
