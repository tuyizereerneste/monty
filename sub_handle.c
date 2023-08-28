#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - substract the top element to second top element of the stack.
 * @head: Double pointer to the top of the stack
 * @number: Line number of the command
 */

void sub(stack_t **head, unsigned int number)
{
	int diff;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	diff = (*head)->next->n - (*head)->n;
	(*head)->next->n = diff;
	pop(head, number);
}
