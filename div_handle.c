#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * division - Divides the two top elements of the stack.
 * @head: Double pointer to the top of the stack
 * @line_number: Line number of the command
 */

void division(stack_t **head, unsigned int line_number)
{
	stack_t *first_top;
	stack_t *second_top;

	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_top = *head;
	second_top = first_top->prev;
	        if (first_top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		second_top->n /= first_top->n;
		*head = second_top;
		if (first_top->prev)
			first_top->prev->next = NULL;
		free(first_top);
}

