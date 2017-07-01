#include <stdio.h>

struct {
  int key;
  int data;
} table[100];

int n = 100;

int search(int key)
{
  int i = 0;
  int table_size = sizeof(table) / sizeof(int);


  while (i < n) {
    /* if found */
    if (table[i].key == key) {
      return table[i].data;
    }
    ++i;
  }

  /* not found */
  return -1;
}

int main()
{
  int x, result;

  for (x = 0; x < 100; ++x) {
    table[x].key = x;
    table[x].data = x + 10000;
  }

  result = search(15);
  printf("result: %d\n", result);

  return 0;
}
