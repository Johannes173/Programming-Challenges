
#include <stdio.h>
#include <stdlib.h>

int** column_numbers(int** matrix, int row, int length)
{
  for(int index = 0; index < length; index++)
  {
    int number = (row * length) + (index + 1);
    *(*(matrix + row) + index) = number;
  }
  return matrix;
}

int** generate_numbers(int** matrix, int length)
{
  for(int index = 0; index < length; index++)
  {
    matrix = column_numbers(matrix, index, length);
  }
  return matrix;
}

int** clean_array(int** matrix, int index, int length)
{
  for(int column = 0; column < length; column++)
  {
    *(*(matrix + index) + column) = 0;
  }
  return matrix;
}

int** generate_matrix_array(int length)
{
  int** matrix = malloc(sizeof(*matrix) * length);
  for(int index = 0; index < length; index++)
  {
    *(matrix + index) = malloc(sizeof(**matrix) * length);
    matrix = clean_array(matrix, index, length);
  }
  return matrix;
}

void show_columns(int** matrix, int row, int length)
{
  for(int index = 0; index < length; index++)
  {
    printf("%d ", *(*(matrix + row) + index));
  }
}

void show_matrix_array(int** matrix, int length)
{
  for(int index = 0; index < length; index++)
  {
    show_columns(matrix, index, length);
    printf("\n");
  }
}
