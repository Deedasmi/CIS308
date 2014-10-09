#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
  char data;
  struct node* next;
} NODE;

NODE* stack;
int count;

void push(char);
char pop(void);
char peek(void);
int charPriority(char);
void popLower(char);

int main() {
  printf("Input an infix equation to be adjusted\n");
  char c[5];
  while (scanf("%s", c) != '\n') {
    if (isdigit(c[0])) {
      printf(" %s ", c);
    }
    else if ( count == 0 ) {
      push(c[0]);
    }
    else {
      popLower(c[0]);
    }

    }
    while (count != 0) {
      printf(" %c ", pop());
    }
    printf(" %c ", stack->data);
  }




void popLower(char c) {
  char c2 = pop();
  if (c2 = '(') {
    if (c != ')') {
      push('(');
    }
    return;
  }
  int cp = charPriority(c);
  int c2p = charPriority(c2);
  while ( cp > c2p) {
    printf(" %c ", c2);
    c2 = pop();
    cp = charPriority(c);
    c2p = charPriority(c2);
  }
  printf(" %c ", c2);
}

int charPriority(char c) {
  int cp;
  if (c == '(' || c == ')') {
    cp = 3;
  }else if (c == '*' || c == '/') {
    cp = 2;
  } else {
    cp = 1;
  }

  return cp;
}
void push(char temp) {
  NODE* newnode = malloc(sizeof(NODE));
  newnode->data = temp;
  //newnode->next = NULL;
  count++;
  newnode->next = stack;
  stack = newnode;
}

char pop(void) {
  //assume not empty
  char temp = stack->data;
  //NODE* nextnode = stack->next;
  //free(s1tack);
  stack = stack->next;
  count--;
  return temp;
}

char peek() {
  return stack->data;
}
