#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pchar - Function that prints the char at the top
 * of the stack, followed by a new line.
 * @head: Double pointer to the top of the stack
 * @number: Line number of the command
 */

void pchar(stack_t **head, unsigned int number)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", number);
		exit(EXIT_FAILURE);
	}
	putchar((*head)->n);
	putchar('\n');
}
