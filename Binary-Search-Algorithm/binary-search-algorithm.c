
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

int generate_integer_array_length(int* array)
{
  int integer_array_length = 0;
  while(*(array + integer_array_length) != '\0')
  {
    integer_array_length += 1;
  }
  return integer_array_length;
}

int generate_new_middle_value(int* bounds)
{
  int difference = (*(bounds + 0) - *(bounds + 0));
  return *(bounds + 0) + ( difference / 2);
}

int* generate_left(int* array, int number, int* bounds)
{
  if(*(array + *(bounds + 2) ) < number)
  {
    *(bounds + 0) = (*(bounds + 2) + 1);
  }
  return bounds;
}

int* generate_right(int* array, int number, int* bounds)
{
  if(*(array + *(bounds + 2) ) > number)
  {
    *(bounds + 1) = (*(bounds + 2) - 1);
  }
  return bounds;
}

int* generate_bounds(int* array, int number, int* bounds)
{
  bounds = generate_left(array, number, bounds);
  bounds = generate_right(array, number, bounds);
  return bounds;
}

int found_search_number(int* array, int* bounds, int number)
{
  return (*(array + *(bounds + 2) ) == number);
}

int generate_results(int* array, int number, int* bounds)
{
  while(*(bounds + 0) <= *(bounds + 1))
  {
    *(bounds + 2) = generate_new_middle_value(bounds);
    if(found_search_number(array, bounds, number))
    {
      return TRUE;
    }
    bounds = generate_bounds(array, number, bounds);
  }
  return FALSE;
}

int check_number_in_array(int* array, int number)
{
  int length = generate_integer_array_length(array);
  int* bounds = (int[]) {0, (length - 1), 0};
  return generate_results(array, number, bounds);
}
