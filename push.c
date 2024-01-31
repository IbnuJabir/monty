#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Push a value onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 * @line: Line containing the value to push
 *
 * Return: None
 */
void push(stack_t **stack, unsigned int line_number, char *line)
{
	stack_t *new_node;
	int value;

	value = atoi(line);

	new_node = malloc(sizeof(stack_t));
	if (line_number < 1)
	{
		fprintf(stderr, "Error: with line - %d", line_number);
		exit(EXIT_FAILURE);
	}
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
