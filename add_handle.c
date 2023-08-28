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
	int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	(*head)->next->n = sum;
	pop(head, number);
}
