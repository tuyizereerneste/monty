#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void swap(stack_t **head, unsigned int number)
{
	int top;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	top = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = top;
}
