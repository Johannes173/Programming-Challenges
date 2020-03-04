
#ifndef BINARY_SEARCH_ALGORITHM_H
#define BINARY_SEARCH_ALGORITHM_H

int generate_integer_array_length(int*);

int generate_new_middle_value(int*);
int* generate_left(int*, int, int*);
int* generate_right(int*, int, int*);
int* generate_bounds(int*, int, int*);

int found_search_number(int, int*, int);
int generate_results(int*, int, int*);
int check_number_in_array(int*, int);

#endif
