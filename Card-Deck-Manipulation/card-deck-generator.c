
#include <stdio.h>
#include <stdlib.h>

int calculate_string_length(char* string)
{
  int string_length = 0;
  while(*(string + string_length) != '\0')
  {
    string_length = string_length + 1;
  }
  return string_length;
}

char* paste_string_together(char* string, char* paste)
{
  int index = 0, length = calculate_string_length(string);
  while(*(paste + index )!= '\0')
  {
    *(string + (index + length)) = *(paste + index); index++;
  }
  return string;
}

char* combine_strings_together(char* first, char* second)
{
  char* result = malloc(sizeof(result));
  result = paste_string_together(result, first);
  result = paste_string_together(result, second);
  return result;
}

char* generate_card_value(char* card, int CIndex, int VIndex)
{
  char* color = *(colors + CIndex);
  char* value = *(values + VIndex);
  return combine_strings_together(value, color);
}

char** generate_deck_values(char** card_deck, int color)
{
  for(int index = 0; index < 13; index++)
  {
    char* card = generate_card_value(card, color, index);
    *(card_deck + ((color * 13) + index) ) = card;
  }
  return card_deck;
}

char** generate_deck_colors(char** card_deck)
{
  for(int index = 0; index < 4; index++)
  {
    card_deck = generate_deck_values(card_deck, index);
  }
  return card_deck;
}

char** generate_empty_card_deck()
{
  char** card_deck = malloc(sizeof(*card_deck) * 4);
  for(int index = 0; index < 13; index++)
  {
    *(card_deck + index) = malloc(sizeof(**card_deck));
  }
  return card_deck;
}

int card_deck_bug_catcher(char** card_deck)
{
  for(int index = 0; index < 52; index++)
  {
    if(calculate_string_length(*(card_deck + index)) > 2 ||
    calculate_string_length(*(card_deck + index)) > 2)
    { return 1; }
  }
  return 0;
}

char** generate_sorted_card_deck()
{
  char** card_deck = generate_empty_card_deck();
  card_deck = generate_deck_colors(card_deck);
  if(card_deck_bug_catcher(card_deck))
  {
    return generate_sorted_card_deck();
  }
  return card_deck;
}
