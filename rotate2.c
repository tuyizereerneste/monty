#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * rotr -  Function that rotates the last element of
 *  the stack becomes the top element of the stack.
 *  @head: Double pointer to the top of the stack
 *  @number: Line number of the command
 */

void rotr(stack_t **head, unsigned int number)
{
	(void)number;

	if (*head && (*head)->next)
	{
		stack_t *last = *head;
		while (last->next)
			last = last->next;
		last->next = *head;
		(*head)->prev = last;
		last->prev->next = NULL;
		last->prev = NULL;
		*head = last;
	}
}
