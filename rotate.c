#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * rotl -  Function that rotates the top element of the stack
 *  becomes the last one, and the second top element
 *  of the stack becomes the first one
 *  @head: Double pointer to the top of the stack
 *  @number: Line number of the command
 */

void rotl(stack_t **head, unsigned int number)
{
	(void)number;

	if (*head && (*head)->next)
	{
		stack_t *last = *head;
		while (last->next)
			last = last->next;
		last->next = *head;
		(*head)->prev = last;
		*head = (*head)->next;
		(*head)->prev = NULL;
		last->next->next = NULL;
	}
}
