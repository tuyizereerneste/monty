#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * division - Divides the two top elements of the stack.
 * @head: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void division(stack_t **head, unsigned int number)
{
	int divide;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", number);
			exit(EXIT_FAILURE);
		}
	divide = (*head)->next->n / (*head)->n;
	(*head)->next->n = divide;
	pop(head, number);
}
