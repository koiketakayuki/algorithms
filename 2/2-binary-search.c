#include <stdio.h>

struct {
  int key;
  int data;
} table[100];

int binary_search(int key)
{
  int low, high, middle;
  low = 0;
  high = sizeof(table) / sizeof(int);

  while (low <= high) {
    middle = (low + high) / 2 + 1;

    if (key == table[middle].key) {
      return table[middle].key;
    } else if (key < table[middle].key) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  return -1;
}

int main() {
  int i, result;

  int table_size = sizeof(table) / sizeof(int);

  for (i = 0; i < table_size; ++i) {
    table[i].key = i;
    table[i].data = i;
  }

  result = binary_search(20);
  printf("result: %d\n", result);
  return 0;
}
