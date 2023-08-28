#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **global_line_args;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **head, unsigned int number);
void pint(stack_t **head, unsigned int number);
void pop(stack_t **head, unsigned int number);
void swap(stack_t **head, unsigned int number);
void add(stack_t **head, unsigned int number);
void nop(stack_t **head, unsigned int number);
void sub(stack_t **head, unsigned int number);
void mul(stack_t **head, unsigned int number);
void division(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int number);
char **tokenize_line(char *line);
void execute_instruction(instruction_t *instruction, stack_t **head, unsigned int number);
instruction_t *find_instruction(const char *opcode);
void pchar(stack_t **head, unsigned int number);
void pstr(stack_t **head, unsigned int number);
void rotl(stack_t **head, unsigned int number);
void rotr(stack_t **head, unsigned int number);

#endif /* MONTY_H */
