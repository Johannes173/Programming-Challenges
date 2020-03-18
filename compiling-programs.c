
#include <stdio.h>
#include <stdlib.h>

#include "Card-Deck-Manipulation/card-deck-manipulation.h"
#include "Card-Deck-Manipulation/card-deck-generator.h"

int main(int argc, char** argv)
{
  char** card_deck = generate_sorted_card_deck();
  show_deck_of_cards(card_deck);
  return 0;
}
