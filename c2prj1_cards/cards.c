#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
//#include "deck.h"

void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value <=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  case NOTHING:
    return "NOTHING";
  default:
    return "NO_SUCH_COMBINATION";
  }
  }

char value_letter(card_t c) {
  switch(c.value){
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case VALUE_JACK: return 'J';
  case VALUE_QUEEN: return 'Q';
  case VALUE_KING: return 'K';
  case VALUE_ACE: return 'A';
  default : return '?';
}
}

char suit_letter(card_t c) {
  switch(c.suit){
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }
}

void print_card(card_t c) {
  char cardval;
  char cardsuit;
    cardval=value_letter(c);
    cardsuit=suit_letter(c);
    printf("%c%c",cardval, cardsuit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch(value_let){
  case '2':
    temp.value=2;
    break;
  case '3':
    temp.value=3;
    break;
  case '4':
    temp.value=4;
    break;
  case '5':
    temp.value=5;
    break;
  case '6':
    temp.value=6;
    break;
  case '7':
    temp.value=7;
    break;
  case '8':
    temp.value=8;
    break;
  case '9':
    temp.value=9;
    break;
  case '0':
    temp.value=10;
    break;
  case 'J':
    temp.value=VALUE_JACK;
    break;
  case 'Q':
    temp.value=VALUE_QUEEN;
    break;
  case 'K':
    temp.value=VALUE_KING;
    break;
  case 'A':
    temp.value=VALUE_ACE;
    break;
  }
  switch(suit_let){
  case 's':
    temp.suit=SPADES;
    break;
  case 'h':
    temp.suit=HEARTS;
    break;
  case 'd':
    temp.suit=DIAMONDS;
    break;
  case 'c':
    temp.suit=CLUBS;
    break;
 }
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int cSuit=c/13;
  int cVal=c%13;
  switch(cSuit){
  case 0:
    temp.suit=SPADES;
    break;
  case 1:
    temp.suit=HEARTS;
    break;
  case 2:
    temp.suit=DIAMONDS;
    break;
  case 3:
    temp.suit=CLUBS;
    break;
  }
  if (cVal>=2){
    temp.value=cVal;
  }else{
    temp.value=cVal+13;
  }

  return temp;
}

/* int main(){ */
/*   printf("Welcome to Poker Calculator\n"); */
/*   card_t c; */
/*   int suitentry; */

/*   printf("insert card value:"); */
  
/*   scanf("%u", &c.value); */
/*   printf("insert card suit:"); */
  
/*   scanf("%d", &suitentry); */


  
/*   c.suit=suitentry; */
 
/*   assert_card_valid(c); */
/*   print_card(c); */
/*   return EXIT_SUCCESS; */
/* } */
