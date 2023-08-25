#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod - Finds the modulus of the two top elements of the stack.
 * @head: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void mod(stack_t **head, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->prev;
	if (first->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
		    second->n %= first->n;
		    *head = second;
		    if (first->prev)
			    first->prev->next = NULL;
		    free(first);
}
