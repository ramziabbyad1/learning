#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

/*
	My stack..
*/

struct Node {
	struct Node *next;
	int data;
};

struct Stack {
	struct Node *top;
	int length;
};

void
free_nodes_r(struct Node *node, int index, int length)
{
	if(node == NULL){
		return;
	}
	free_nodes_r(node->next, index + 1, length);
	printf("Freeing a node...\n");
	free(node);
}

void
free_nodes(struct Node *node, int length)
{
	int starting_index = 0;
	free_nodes_r(node, starting_index, length);
}

int
get_stack_length(struct Stack *stack)
{
	int length = 0;
	struct Node *node = stack->top;
	while(node != NULL) {
		node = node->next;
		++length;
	}
	return length;
}

void
set_stack_length(struct Stack *stack)
{
	int length = get_stack_length(stack);
	stack->length = length;
}

void
free_stack(struct Stack *stack)
{
	if(stack->top != NULL)
		free_nodes(stack->top, stack->length);
	free(stack);
}

void 
die(const char *message, struct Stack *stack)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	free_stack(stack);
	exit(1);
}

int
pop(struct Stack *stack)
{
	if(stack->top != NULL) {
		int data = stack->top->data;
		struct Node *top = stack->top;
		stack->top = stack->top->next;
		free(top);
		--stack->length;
		return data;
	}
	die("Tried to pop an empty stack.", stack);
	return -1;
}

void
push(struct Stack *stack, int data)
{
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
	++stack->length;
}

int
peek(struct Stack *stack)
{
	return stack->top->data;
}

int
main()
{
	struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
	push(stack, 20);
	push(stack, 30);
	set_stack_length(stack);
	printf("set stack length to : %d\n", stack->length);
	int res = pop(stack);
	printf("The result of popping should be 30: %d\n", res);
	res = pop(stack);
	printf("The result of popping should be 20: %d\n", res);
	push(stack, 90);
	push(stack, 100);
	res = peek(stack);
	printf("The result of peeping should be 100: %d\n", res);
	free_stack(stack);
	return 0;
}
