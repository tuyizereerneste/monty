#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

char **global_line_args;

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char line[MAX_LINE_LENGTH];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;

		global_line_args = tokenize_line(line);
		if (global_line_args[0])
		{
			instruction_t *instruction = find_instruction(global_line_args[0]);
			execute_instruction(instruction, &stack, line_number);
		}
		free(global_line_args);
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

