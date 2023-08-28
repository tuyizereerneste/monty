#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pstr - Function that prints the string starting
 *  at the top of the stack, followed by a new line.
 *  @head: Double pointer to the top of the stack
 *  @number: Line number of the command
 */

void pstr(stack_t **head, unsigned int number)
{
	stack_t *current = *head;
	(void)number;
       
	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
