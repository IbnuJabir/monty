#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - Push a value onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 *
 * Return: None
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
