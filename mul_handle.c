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
	int product;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	product = (*head)->next->n * (*head)->n;
	(*head)->next->n = product;
	pop(head, number);
}
