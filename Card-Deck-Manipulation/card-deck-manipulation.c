
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* colors[] = {"D", "H", "S", "C"};
char* values[] = {"A", "2", "3", "4", "5",
"6", "7", "8", "9", "T", "N", "Q", "K"};

int calculate_string_length(char* string)
{
  int string_length = 0;
  while(*(string + string_length) != '\0')
  {
    string_length = string_length + 1;
  }
  return string_length;
}

void show_deck_of_cards(char** card_deck)
{
  for(int index = 0; index < 52; index++)
  {
    printf("%d. Card: %s\n", index + 1, card_deck[index]);
  }
}

char** switch_card_deck_values(char** card_deck, int index)
{
  int random_index = (rand() % 51);
  char* switch_value = *(card_deck + index);
  *(card_deck + index) = *(card_deck + random_index);
  *(card_deck + random_index) = switch_value;
  return card_deck;
}

char** generate_shuffled_card_deck(char** card_deck)
{
  srand(time(NULL));
  for(int index = 0; index < 52; index++)
  {
    card_deck = switch_card_deck_values(card_deck, index);
  }
  return card_deck;
}
