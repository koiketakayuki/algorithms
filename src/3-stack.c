#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long ELEMENT;

#define STACK_SIZE 100

ELEMENT stack[STACK_SIZE];
int n;/* Stack Pointer */

void error(const char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void initialize()
{
  n = 0;
}

void push(ELEMENT e)
{
  if (n >= STACK_SIZE) {
    error("stack overflow\n");
  }
  printf("push: %ld\n", e);
  stack[++n] = e;
}

ELEMENT pop()
{
  if (n <= 0) {
    error("stack underflow\n");
  }
  printf("pop\n");
  return stack[n--];
}

int empty()
{
  return n == 0;
}

int main()
{
  int c;
  long x, a, b;

  initialize();

  while ((c = getchar()) != EOF) {
    if (isdigit(c)) {
      ungetc(c, stdin);
      scanf("%ld", &x);
      push(x);
    } else {
      switch (c) {
        case '+':
          b = pop();
          a = pop();
          push(a + b);
          break;
        case '-':
          b = pop();
          a = pop();
          push(a - b);
          break;
        case '*':
          b = pop();
          a = pop();
          push(a * b);
          break;
        case '/':
          b = pop();
          a = pop();
          push(a / b);
          break;
        case '\n':
          if (!empty()) {
            printf("Answer: %ld", pop());
          }
          printf("init");
          initialize();
          break;
        case ' ':
        case '\t':
          break;
        default:
          printf("Invalid character given\n");
      }
    }
  }
}
