#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "deck.h"
#include "future.h"
#include "input.h"
#include "cards.h"

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  assert(f!=NULL);
  size_t num = 0;
  size_t sz = 0;
  char * line = NULL;
  deck_t ** r_deck = NULL;
  while(getline(&line, &sz, f)!=EOF){

    // create a hand from each valid line in file
    r_deck=realloc(r_deck,sizeof(* r_deck)*(num+1));
    deck_t * temp = hand_from_string(line,fc);
    if (temp!=NULL){
      // import "temp" to returned deck
      r_deck[num]=temp;
      num++;
    }else{
      // if line invalid go to next line or end if EOF
      continue;
    }
    
    
  }
  * n_hands = num;
  free(line);
  return r_deck;
}



deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t * deck=malloc(sizeof(*deck));
  deck->cards=NULL;
  deck->n_cards=0;

  // analyse imported line
  for (int i=0; i<strlen(str); i++){

    // ignore characters space or newline
    if(str[i] == ' ' || str[i] == '\n') continue;
    
    // if card is not unknown, add it
    if(str[i] != '?') {
      card_t card = card_from_letters(str[i], str[i+1]);
      add_card_to(deck,card);
      i++;
    }else{
      // if card is unknown add a future card
      char str_n[strlen(str)];
      int n=0;
      i++;

      // copy all card characters to the string up to next newline or space
      while (!(str[i] == ' '|| str[i] == '\n' )){
	str_n[n]=str[i];
	i++;
	n++;
      }
      // finish card string with terminator
	str_n[n]= '\0';
	add_future_card(fc, atoi(str_n), add_empty_card(deck));
      }
    }

  // hands have to be minimum 5 cards
  if (deck->n_cards < 5) {
    fprintf(stderr, "Hands smaller than 5 cards");
    return NULL;
  }
  return deck;

}
