#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
	char* root;
	struct tree* right;
	struct tree* left;
} TREE;

typedef struct node {
	TREE* data;
	struct node* next;
} NODE;

TREE* expression;
NODE* stack;

TREE* create(char*, TREE*, TREE*);
void push(TREE*);
TREE* pop(void);
void inorder(TREE*);
void freeTree(TREE*);

int main() {
	char buff[100];
	char *token;
	int answer;

	expression = NULL;
	stack = NULL;

	printf("Enter postfix expression: ");
	fgets(buff, 100, stdin);
	buff[strlen(buff)-1] = '\0';

	token = strtok(buff, " ");
	while (token != NULL) {
		if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
			TREE *x, *y, *result;
			y = pop();
			x = pop();

			result = create(token, x, y);
			push(result);
		}
		else {
			TREE* temp = create(token, NULL, NULL);
			push(temp);
		}
		token = strtok(NULL, " ");
	}

	//should be just the final expression tree on the stack.
	expression = pop();

	//now expression tree is built.  Do inorder traversal.
	printf("In infix: ");
	inorder(expression);
	printf("\n\n");

	//free tree memory
	freeTree(expression);

	return 0;
}

TREE* create(char* root, TREE* left, TREE* right) {
	TREE* temp = malloc(sizeof(TREE));
	temp->root = root;
	temp->left = left;
	temp->right = right;

	return temp;
}

void push(TREE* temp) {
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = temp;
	newnode->next = NULL;

	newnode->next = stack;
	stack = newnode;
}

TREE* pop(void) {
	//assume not empty
	TREE* temp = stack->data;
	NODE* nextnode = stack->next;
	free(stack);
	stack = nextnode;

	return temp;
}

void inorder(TREE* exp) {
	if (exp == NULL) return;
	if (exp->left != NULL) printf("(");
	inorder(exp->left);
	printf("%s", exp->root);
	inorder(exp->right);
	if (exp->right != NULL) printf(")");
}

void freeTree(TREE* top) {
	if (top == NULL) return;
	freeTree(top->left);
	freeTree(top->right);
	free(top);
}
