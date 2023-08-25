#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *top = NULL;

void push(int value)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = top;
	newNode->next = NULL;
	if (top != NULL)
		top->next = newNode;
	top = newNode;
}
