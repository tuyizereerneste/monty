#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mod - Finds the modulus of the two top elements of the stack.
 * @head: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void mod(stack_t **head, unsigned int number)
{
	int modulus;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", number);
		exit(EXIT_FAILURE);
	}
	modulus = (*head)->next->n % (*head)->n;
	(*head)->next->n = modulus;
	pop(head, number);
}
