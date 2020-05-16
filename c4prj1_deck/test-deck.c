#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"

int main(){
  deck_t * testDeck=malloc(sizeof(* testDeck));
  testDeck->n_cards=0;
  testDeck->cards=NULL;

  deck_t * testDeck2=malloc(sizeof(* testDeck2));
  testDeck2->n_cards=0;
  testDeck2->cards=NULL;

  deck_t * testDeck3=malloc(sizeof(* testDeck3));
  testDeck3->n_cards=0;
  testDeck3->cards=NULL;
  
  
  card_t testCard;
  for (int i=0; i<51; i++){
    testCard = card_from_num(i);
    add_card_to(testDeck, testCard);
  }
    add_empty_card(testDeck);

    for (int i=0; i<3; i++){
      testCard = card_from_num(i);
      add_card_to(testDeck2, testCard);
      testDeck3 = make_deck_exclude(testDeck2);
    }

    
  printf("testDeck length is now %zu\n", testDeck->n_cards);
  print_hand(testDeck);
  print_hand(testDeck3);
  
  printf("RUNNING TESTS\n");
  free_deck(testDeck);
  free_deck(testDeck2);
  free_deck(testDeck3);
  return 0;
}
