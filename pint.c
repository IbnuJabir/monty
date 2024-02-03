#include "monty.h"
/**
 * pint - Print the value at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 *
 * Return: None
 */
void pint(stack_t **stack, unsigned int line_number)
{
	arg = NULL;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
