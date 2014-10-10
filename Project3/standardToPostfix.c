#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
  char data;
  struct node* next;
} NODE;
//Initialize head of stack
NODE* stack;

//Keeps track of the number of elements in the stack.
int count;

void push(char);
char pop(void);
char peek(void);
int charPriority(char);
void popLower(char);

int main() {
  printf("Input an infix equation to be adjusted\n");
  char c[5]; // Array simply to allow multiple digits
  while (c[0] != '\n') { //scanf doesn't grab new line characters. Had to improvise
    scanf("%s", c);
    if (isdigit(c[0])) { //If it has a digit in the beginning the whole thing is a number
      printf(" %s ", c);
    }
    else if ( count == 0 ) { //If we don't have anything else we assume we are supposed to push
      push(c[0]);
    }
    else {
      popLower(c[0]); //Pop everything with a lower priority
      if (c[0] != ')') { //Don't push )
        push(c[0]);
      }
    }
    c[0] = (char)getchar(); // Check for newline characte
  }

  while (count != 0 && peek() != '(') { //print everything except extra (
    printf(" %c ", pop());
  }
  printf("\n"); //Friendly new line character
  free(stack);
}




void popLower(char c) {
  char temp; //This was an int on accident, but everything worked. Ints and chars are very compatible.
  if (c == ')') {
    temp = pop();
    while (temp != '(') {
      printf(" %c ", temp);
      temp = peek();
    }
    if ( temp == '(') { //If we found a (, remove it from the stack
      temp = pop();
    }
    return;
  }
  if (c == '(') { //Don't check priority on (
    return;
  }
  while ( count != 0 && charPriority(c) >= charPriority(peek())) {
    printf(" %c ", pop());
  }
  return;
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
  count++;
  newnode->next = stack;
  stack = newnode;
}

char pop(void) {
  //assume not empty
  char temp = stack->data;
  NODE* nextnode = stack->next;
  free(stack); //Clear stack because no garbage collector
  stack = nextnode;
  count--;
  return temp;
}

char peek() {
  return stack->data;
}
