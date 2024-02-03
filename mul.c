#include "monty.h"

/**
 * mul - Multiply the second top element by the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
