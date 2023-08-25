#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void swap(stack_t **head, unsigned int n)
{
	stack_t *top;
	stack_t *next_top;


	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	top = *head;
	next_top = top->prev;
	top->prev = next_top->prev;
	if (next_top->prev)
		next_top->prev->next = top;
	next_top->prev = top;
	top->next = next_top;
	next_top->next = NULL;
	*head = next_top;
}
