#include "monty.h"
#include <stdio.h>

/**
 * print_stack - Function that prints all elements of the stack.
 * Return: nothing
 */

void print_stack()
{
	stack_t *current = top;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
