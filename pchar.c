#include "monty.h"

/**
 * pchar - Print the char at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isascii((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
