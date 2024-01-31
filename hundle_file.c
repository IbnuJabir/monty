#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * handle_file - Handle file operations
 * @filename: Name of the file to handle
 *
 * Return: None
 */
void handle_file(const char *filename)
{
	FILE *file;
	char line[100];
	char *command;
	char *argument;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file\n");
		return;
	}

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';

		command = strtok(line, " $");
		argument = strtok(NULL, " $");

		if (command != NULL)
		{
			if (strcmp(command, "push") == 0 && argument != NULL)
			{
				push(&stack, line_number, argument);
			}
			else if (strcmp(command, "pall") == 0)
			{
				pall(&stack);
			}
		}

		line_number++;
	}

	fclose(file);
}
