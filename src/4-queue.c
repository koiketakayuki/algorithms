#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEMENT;

#define QUEUE_SIZE 5

ELEMENT queue[QUEUE_SIZE];

int front;
int rear;

#define next(a) (((a) + 1) % QUEUE_SIZE)

void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void initialize()
{
  front = 0;
  rear = 0;
}

int is_empty()
{
  return front == rear;
}

void enqueue(ELEMENT e)
{
  if (next(rear) == front) {
    error("Queue overflow");
  }
  queue[rear] = e;
  rear = next(rear);
}

ELEMENT dequeue()
{
  ELEMENT x;

  if (is_empty()) {
    error("Empty queue");
  }

  x = queue[front];
  front = next(front);
  return x;
}


void inspect()
{
  int i;

  printf("front %d, rear %d\n", front, rear);

  for (i = 0; i < QUEUE_SIZE; ++i) {
    ELEMENT e = queue[i];
    printf(" queue[%d]: %ld", i, e);
    if (i == front) {
      printf(" <- front");
    }
    if (i == rear) {
      printf(" <- rear");
    }
    printf("\n");
  }
}

int main()
{
  initialize();

  int x;

  for (x = 100; x < QUEUE_SIZE + 100 - 1; ++x) {
    enqueue(x);
    dequeue();
    inspect();
  }

}
