#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds the top element to second top element of the stack.
 * @head: Double pointer to the top of the stack
 * @number: Line number of the command
 */

void add(stack_t **head, unsigned int number)
{
	stack_t *top;
	stack_t *next_top;

	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	top = *head;
	next_top = top->prev;
	next_top->n += top->n;
	*head = next_top;
	if (top->prev)
		top->prev->next = NULL;
	free(top);
}

