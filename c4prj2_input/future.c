#include <stdio.h>
#include <stdlib.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  // deck_t * d_index = &fc->decks[index];

  if(index < fc->n_decks){
  fc->decks[index].cards=realloc(fc->decks[index].cards, sizeof(* fc->decks[index].cards)*(fc->decks[index].n_cards+1));

  fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
  fc->decks[index].n_cards++;
}

  if(index >= fc->n_decks){
    while(fc->n_decks <= index){
      // deck_t * d_ndecks = &fc->decks[fc->n_decks];
      // increase number of decks and insert initialized deck in fc
      fc->decks=realloc(fc->decks, sizeof(* fc->decks)*(fc->n_decks+1));

      fc->decks[fc->n_decks].cards=NULL;
      fc->decks[fc->n_decks].n_cards=0;
      fc->n_decks++;
    }
    // increase size of fc decks [index] and insert card
    fc->decks[index].cards = realloc(fc->decks[index].cards, sizeof(* fc->decks[index].cards)*(fc->decks[index].n_cards+1));

    fc->decks[index].cards[fc->decks[index].n_cards]=ptr;
    fc->decks[index].n_cards++;
  }
}
      
void future_cards_from_deck(deck_t * deck, future_cards_t * fc){

  if (deck->n_cards < fc->n_decks){
    fprintf(stderr, "Not enough cards to draw and replace all future cards \n");
    return;
  }
  for (int i=0; i<fc->n_decks;i++){
    if (fc->decks[i].n_cards==0){
      continue;
    }
    for (int x=0; x<fc->decks[i].n_cards; x++){

      *(fc->decks[i].cards[x]) = *(deck->cards[i]);
    }
  }
}
