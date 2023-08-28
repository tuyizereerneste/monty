#include "monty.h"
#include <stdio.h>

/**
 * print_stack - Function that prints all elements of the stack.
 * Return: nothing
 */

void pall(stack_t **head, unsigned int number)
{
	stack_t *current = *head;
	(void)number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
