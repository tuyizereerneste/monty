#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Removes the top element of the stack.
 * @head: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void pop(stack_t **stack, unsigned int number)
{
	stack_t *temp;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
