#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number)
{
	int value;

	stack_t *newNode;

	if (!global_line_args[1])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		                                                exit(EXIT_FAILURE);
								                                                    }
	value = atoi(global_line_args[1]);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	if (!*stack)
	{
	newNode->next = NULL;
	*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}
