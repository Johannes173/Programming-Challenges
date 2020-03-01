
#include <stdio.h>
#include <stdlib.h>

int** switch_integers(int** matrix, int* curr, int* next)
{
  int swap_number = matrix[curr[0]][curr[1]];
  matrix[curr[0]][curr[1]] = matrix[next[0]][next[1]];
  matrix[next[0]][next[1]] = swap_number;
  return matrix;
}

int** horizontal_columns(int** matrix, int length, int row)
{
  for(int index = 0; index < (length / 2); index++)
  {
    int current[] = {row, index};
    int next[] = {row, length - 1 - index};
    matrix = switch_integers(matrix, current, next);
  }
  return matrix;
}

int** diagonal_columns(int** matrix, int length, int row)
{
  for(int index = row; index < length; index++)
  {
    int current[] = {row, index}, next[] = {index, row};
    matrix = switch_integers(matrix, current, next);
  }
  return matrix;
}

int** switch_horizontal_numbers(int** matrix, int length)
{
  for(int index = 0; index < length; index++)
  {
    matrix = horizontal_columns(matrix, length, index);
  }
  return matrix;
}

int** switch_diagonal_numbers(int** matrix, int length)
{
  for(int index = 0; index < length; index++)
  {
    matrix = diagonal_columns(matrix, length, index);
  }
  return matrix;
}

int** rotate_matrix_quarter(int** matrix, int length)
{
  matrix = switch_diagonal_numbers(matrix, length);

  matrix = switch_horizontal_numbers(matrix, length);

  return matrix;
}

int** rotate_matrix_half(int** matrix, int length)
{
  for(int index = 0; index < 2; index++)
  {
    matrix = rotate_matrix_quarter(matrix, length);
  }
  return matrix;
}

int** rotate_matrix_back(int** matrix, int length)
{
  for(int index = 0; index < 3; index++)
  {
    matrix = rotate_matrix_quarter(matrix, length);
  }
  return matrix;
}
