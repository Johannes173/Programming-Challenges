
#include <stdio.h>
#include <stdlib.h>

#include "First-Second-Index/first-second-index.h"

int main(int argc, char** argv)
{
  int* array = (int[]) {1, 2, 2, 3, 3, 3, '\0'};
  int* indexes = generate_sequence_index(array, 3);
  printf("INDEX: (%d, %d)\n", *(indexes + 0), *(indexes + 1));
  return 0;
}
