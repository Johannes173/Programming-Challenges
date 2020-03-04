
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1

int* switch_array_numbers(int* array, int index)
{
  if(*(array + index) > *(array + index + 1))
  {
    int switch_integer = *(array + index);
    *(array + index) = *(array + index + 1);
    *(array + index + 1) = switch_integer;
  }
  return array;
}

int* bubble_sort_columns(int* array, int length)
{
  for(int index = 0; index < length - 1; index++)
  {
    array = switch_array_numbers(array, index);
  }
  return array;
}

int* bubble_sort_array(int* array, int length)
{
  for(int index = length; index >= 0; index--)
  {
    array = bubble_sort_columns(array, index);
  }
  return array;
}

int generate_sequence_length(int* array, int begin)
{
  int index = (begin + 1), counter = 1;
  while(*(array + index) == *(array + begin) + counter)
  {
    index = (index + 1); counter = (counter + 1);
  }
  return (index - begin);
}

int generate_maximum_length(int maximum, int current)
{
  if(maximum >= current)
  {
    return maximum;
  }
  return current;
}

int calculate_maximum_length(int* array, int length)
{
  array = bubble_sort_array(array, length); int maximum;
  for(int index = 0; index < length; index++)
  {
    int current = generate_sequence_length(array, index);
    maximum = generate_maximum_length(maximum, current);
  }
  return maximum;
}
