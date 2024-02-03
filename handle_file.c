#include "monty.h"

/**
 * handle_file - Handle file operations
 * @filename: Name of the file to handle
 *
 * Return: None
 */
char *arg = NULL;
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
}

/**
 * process_line - Process a line from the file
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

    command = strtok(line, " $\t\n");
    argument = strtok(NULL, " $\t\n");

    arg = argument;
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
void handle_instruction(char *command, char *argument, stack_t **stack, unsigned int line_number)
{
    instruction_t opst[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
    };

    int num_opcodes = sizeof(opst) / sizeof(instruction_t);
    int i;

    for (i = 0; i < num_opcodes; i++)
    {
        if (strcmp(command, opst[i].opcode) == 0)
        {
	if (argument != NULL)
	{
            arg = argument;
	}
            opst[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
    exit(EXIT_FAILURE);
}
