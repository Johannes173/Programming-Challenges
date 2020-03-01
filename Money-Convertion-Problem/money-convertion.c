
#include <stdio.h>
#include <stdlib.h>

const int values[] = {1, 2, 5, 10, 20, 50, 100};
int length = sizeof(values) / sizeof(values[0]);

int* generate_integer_array(int size)
{
  int* array = malloc(sizeof(array) * size);
  for(int index = 0; index < size; index++)
  {
    *(array + index) = '\0';
  }
  return array;
}

int integer_array_length(int* array)
{
  int array_length = 0;
  while(*(array + array_length) != '\0')
  {
    array_length = array_length + 1;
  }
  return array_length;
}

int* add_values(int* array, int value, int amount)
{
  int index = integer_array_length(array);
  while( (amount - *(values + value)) >= 0)
  {
    *(array + index) = *(values + value);
    index = index + 1; amount -= *(values + value);
  }
  return array;
}

int remove_amount_money(int amount, int value)
{
  while( (amount - *(values + value)) >= 0)
  {
    amount = amount - *(values + value);
  }
  return amount;
}

int* generate_values(int amount)
{
  int* array = generate_integer_array(20);
  for(int index = length - 1; index >= 0; index--)
  {
    array = add_values(array, index, amount);
    amount = remove_amount_money(amount, index);
  }
  return array;
}

int generate_amount(int* array)
{
  int money = integer_array_length(array);
  int amount = 0;
  for(int index = 0; index < money; index++)
  {
    amount = amount + *(array + index);
  }
  return amount;
}
