#include <stdio.h>
#include <stdlib.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  deck_t * d_index = &fc->decks[index];

  if(index < fc->n_decks){
  d_index->cards=realloc(d_index->cards, sizeof(* d_index->cards)*(d_index->n_cards+1));
  d_index->cards[d_index->n_cards]=ptr;
  d_index->n_cards++;
}

  if(index >= fc->n_decks){
    while(fc->n_decks <= index){
      deck_t * d_ndecks = &fc->decks[fc->n_decks];
      
      fc->decks=realloc(fc->decks, sizeof(* fc->decks)*(fc->n_decks+1));
      d_ndecks->cards=NULL;
      d_ndecks->n_cards=0;
      fc->n_decks++;
    }
    d_index->cards = realloc(d_index->cards, sizeof(* d_index->cards)*(d_index->n_cards+1));
      d_index->cards[d_index->n_cards]=ptr;
    d_index->n_cards++;
  }
}
      
void future_cards_from_deck(deck_t * deck, future_cards_t * fc){


  for (int i=0; i<fc->n_decks;i++){
    if (fc->decks[i].n_cards==0){
      continue;
    }
    for (int x=0; x<fc->decks[i].n_cards; x++){
      card_t temp = *(deck->cards[i]);
      (*(fc->decks[i].cards[x])) = temp;
    }
  }
}