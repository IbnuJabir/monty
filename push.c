#include "monty.h"
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
	int a;

	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	a = atoi(arg);

	new_node->n = a;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;

	new_node = NULL;
}

/**
 * is_number - Check if a string is a valid number
 * @str: String to check
 *
 * Return: (1) if the string is a number, (0) otherwise
 */
int is_number(const char *str)
{
	if (*str == '-')
	{
		str++;
	}

	if (*str == '\0')
	{
		return (0);
	}

	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}

	return (1);
}
