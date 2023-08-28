#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

char **tokenize_line(char *line)
{
	char **args;
	char *token;
	int count;
	args = malloc(sizeof(char *) * MAX_ARGS);
	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	count = 0;
	
	while (token != NULL)
	{
		args[count] = malloc(strlen(token) + 1);
		if (!args[count])
		{
			fprintf(stderr, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(args[count], token);
		token = strtok(NULL, " \t\n");
		count++;
		if (count >= MAX_ARGS)
			break;
	}
	args[count] = NULL;
	return (args);
}
