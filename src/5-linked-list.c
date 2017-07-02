#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int

struct Cell {
  ELEMENT value;
  struct Cell *next;
} header;

void error(char *message) {
  fprintf(stderr, message);
  exit(1);
}

void inspect()
{
  struct Cell *cell;
  cell = &header;

  printf("(");

  cell = cell->next;

  if (cell != NULL) {
      printf("%d", cell->value);
      cell = cell->next;

      while (cell != NULL) {
        printf(", ");
        printf("%d", cell->value);
        cell = cell->next;
      }
  }

  printf(")\n");
}

void insert(ELEMENT e)
{
  struct Cell *p, *q, *new;
  p = header.next;
  q = &header;

  while (p != NULL && p->value < e) {
    q = p;
    p = p->next;
  }

  if ((new = malloc(sizeof(struct Cell))) == NULL) {
    error("Memory shortage");
  }

  new->value = e;
  q->next = new;
  new->next = p;
}

void delete(int i)
{
  int counter = 0;
  struct Cell *p, *q;
  p = header.next;
  q = &header;

  while (counter < i) {
    if (p == NULL) {
      error("End of list");
    }
    q = p;
    p = p->next;
    ++counter;
  }

  q->next = p->next;
  free(p);
}

int main()
{
  inspect();
  insert(10);
  inspect();
  insert(20);
  inspect();
  insert(30);
  insert(50);
  inspect();
  insert(3);
  inspect();
  delete(4);
  inspect();
}
