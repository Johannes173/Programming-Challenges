
#include <stdio.h>
#include <stdlib.h>

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

int generate_integer_array_length(int* array)
{
  int integer_array_length = 0;
  while(*(array + integer_array_length) != '\0')
  {
    integer_array_length += 1;
  }
  return integer_array_length;
}

int generate_first_index(int* array, int number)
{
  int length = generate_integer_array_length(array);
  for(int index = 0; index < length; index++)
  {
    if(*(array + index) == number)
    {
      return index;
    }
  }
  return -1; // Number didn't exsist;
}

int generate_second_index(int* array, int first)
{
  int length = generate_integer_array_length(array);
  for(int index = first; index < length; index++)
  {
    if(*(array + index) != *(array + first))
    {
      return (index - 1);
    }
  }
  return (length - 1); // Every number is the same;
}

int* generate_sequence_index(int* array, int number)
{
  int length = generate_integer_array_length(array);

  array = bubble_sort_array(array, length);

  int first = generate_first_index(array, number);

  int second = generate_second_index(array, first);
  return (int[]) {first, second};
}
