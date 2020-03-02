
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* square_integer_array(int* array, int length)
{
  for(int index = 0; index < length; index++)
  {
    *(array + index) = pow(*(array + index), 2);
  }
  return array;
}

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

int* sort_squared_array(int* array, int length)
{
  array = square_integer_array(array, length);
  array = bubble_sort_array(array, length);
  return array;
}
