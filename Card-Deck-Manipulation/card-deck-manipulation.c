
#include <stdio.h>
#include <stdlib.h>

void show_deck_of_cards(char** card_deck)
{
  for(int index = 0; index < 52; index++)
  {
    printf("%s\n", card_deck[index]);
  }
}
