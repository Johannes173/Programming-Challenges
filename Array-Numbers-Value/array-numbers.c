
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int integer_array_length(int* integer_array)
{
  int array_length = 0;
  while(*(integer_array + array_length) != '\0')
  {
    array_length++;
  }
  return array_length;
}

int check_addition_number(int first, int second, int number)
{
  return (first + second) == number;
}

int check_multi_number(int first, int second, int number)
{
  return (first * second) == number;
}

int check_division_number(int first, int second, int number)
{
  return (first / second) == number ||
         (second / first) == number;
}

int check_subtraction_number(int first, int second, int number)
{
  return (first - second) == number ||
         (second - first) == number;
}

int check_array_number(int first, int second, int number)
{
  return (check_addition_number(first, second, number) ||
  check_multi_number(first, second, number) ||
  check_division_number(first, second, number) ||
  check_subtraction_number(first, second, number));
}

int check_other_array(int first, int* second, int number)
{
  int length = integer_array_length(second);
  for(int index = 0; index < length; index++)
  {
    int second_number = *(second + index);
    if(check_array_number(first, second_number, number))
    {
      return true;
    }
  }
  return false;
}

int possible_number(int number, int* first, int* second)
{
  int length = integer_array_length(first);
  for(int index = 0; index < length; index++)
  {
    int first_number = *(first + index);
    if(check_other_array(first_number, second, number))
    {
      return true;
    }
  }
  return false;
}
