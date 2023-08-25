#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pint - Function that Prints the value
 * at the top of the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @number: Line number of the opcode in the file.
 */

void pint(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
