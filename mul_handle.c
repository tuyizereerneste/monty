#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  * mul - Multiplies the two top elements of the stack.
 *  @head: Double pointer to the top of the stack
 *  @number: Line number of the command
 */

void mul(stack_t **head, unsigned int number)
{
	stack_t *first;
	stack_t *second;

	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	first = *head;
	second = first->prev;
	second->n *= first->n;
	*head = second;
	if (first->prev)
		first->prev->next = NULL;
	free(first);
}
