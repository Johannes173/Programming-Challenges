
#include <stdio.h>
#include <stdlib.h>

#include "Sorted-Squared-Array/sorted-squared-array.h"

int main(int argc, char** argv)
{
  int* array = (int[]) {5, 2, 14, 7, 3, 7};
  array = sort_squared_array(array, 6);
  for(int index = 0; index < 6; index++)
  {
    printf("Square: %d\n", *(array + index));
  }
  return 0;
}
