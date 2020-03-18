
#include <stdio.h>
#include <stdlib.h>

int switch_lowest_indexes(int* array, int lowest, int index)
{
  if(*(array + index) < *(array + lowest))
  {
    return index;
  }
  return lowest;
}

int generate_lowest_index(int* array, int length, int curr)
{
  int lowest = curr;
  for(int index = curr; index <= length - 1; index++)
  {
    lowest = switch_lowest_indexes(array, lowest, index);
  }
  return lowest;
}

int* switch_array_values(int* array, int first, int second)
{
  int switch_value = *(array + first);
  *(array + first) = *(array + second);
  *(array + second) = switch_value;
  return array;
}

int* generate_index_number(int* array, int length, int index)
{
  int lowest = generate_lowest_index(array, length, index);
  return switch_array_values(array, index, lowest);
}

int* selection_sort_array(int* array, int length)
{
  for(int index = 0; index <= length - 1; index++)
  {
    array = generate_index_number(array, length, index);
  }
  return array;
}

// H4PE0N - 2020 / 03 / 12
