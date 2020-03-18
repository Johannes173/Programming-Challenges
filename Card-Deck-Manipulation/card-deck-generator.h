
#ifndef CARD_DECK_GENERATOR_H
#define CARD_DECK_GENERATOR_H

char* paste_string_together(char*, char*);
char* combine_strings_together(char*, char*);
char* generate_card_value(int, int);

char** generate_deck_values(char*, int);
char** generate_deck_colors(char**);

int calculate_string_length(char*);
char** generate_empty_card_deck();
int card_deck_bug_catcher(char**);
char** generate_sorted_card_deck();

#endif
