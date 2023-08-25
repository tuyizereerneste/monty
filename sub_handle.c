#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void sub(stack_t **head, unsigned int number)
{
	stack_t *top;
	stack_t *second_top;

	if (*head == NULL || (*head)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", number);
		exit(EXIT_FAILURE);
	}
	top = *head;
	second_top = top->prev;
	second_top->n -= top->n;
	*head = second_top;
	if (top->prev)
		top->prev->next = NULL;
	free(top);
}

