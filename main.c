#include <stdlib.h>
#include "monty.h"
#include <stdio.h>

char **global_line_args;

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
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
	while (fgets(line, len, file) != NULL)
	{
		line_number++;

		printf("Line %d: %s", line_number, line);

		global_line_args = tokenize_line(line);
		if (global_line_args[0])
		{
			instruction_t *instruction = find_instruction(global_line_args[0]);
			execute_instruction(instruction, &stack, line_number);
		}
		free(global_line_args);
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

