#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"sub", sub},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"div", division},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL} }
	;

instruction_t *find_instruction(const char *opcode)
{
	size_t i;
	
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			return &instructions[i];
		}
	}
	return NULL;
}

/**
 * execute_instruction - Executes a given instruction.
 * @instruction: The instruction to execute.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */

void execute_instruction(instruction_t *instruction, stack_t **head, unsigned int number)
{
	if (instruction && instruction->f)
		instruction->f(head, number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", number, global_line_args[0]);
		exit(EXIT_FAILURE);
	}
}
