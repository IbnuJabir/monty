#include "monty.h"
/**
 * handle_file - Handle file operations
 *
 * @filename: Name of the file to handle
 *
 * Return: None
 */

void handle_file(const char *filename)
{
	FILE *file;
	char line[100];
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line[strcspn(line, "\n")] = '\0';
		process_line(line, &stack, line_number);
		line_number++;
	}

	fclose(file);
	free_stack(&stack);
	free(arg);
}

/**
 * process_line - Process a line from the file
 *
 * @line: Line to process
 * @stack: Pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *command;
	char *argument;

	/* Skip lines starting with '#' or having spaces/tabs before '#' */
	size_t i;

	for (i = 0; i < strlen(line); i++)
	{
		if (line[i] == '#' || (!isspace((unsigned char)line[i]) && line[i] != '\t'))
			break;
	}

	/* starts with '#' after spaces/tabs, skip it */
	if (i == strlen(line) || line[i] == '#')
		return;

	command = strtok(line, " $\t\n");
	argument = strtok(NULL, " $\t\n");

	if (command != NULL)
	{
		handle_instruction(command, argument, stack, line_number);
	}
}

/**
 * handle_instruction - Handle a specific instruction
 * @command: Instruction command
 * @argument: Instruction argument
 * @stack: Pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void handle_instruction(char *command, char *argument,
stack_t **stack, unsigned int line_number)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", fdiv},
		{"mul", mul},
		{"mod", mod},
		{"pchr", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
	};

	int num_opcodes = sizeof(opst) / sizeof(instruction_t);
	int i;

	arg = argument;

	for (i = 0; i < num_opcodes; i++)
	{
		if (strcmp(command, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
