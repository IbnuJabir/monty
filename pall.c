#include "monty.h"
/**
 * pall - Print all elements on the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	arg = NULL;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
