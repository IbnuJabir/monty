#include "monty.h"

/**
 * pall - Print all elements on the stack
 * @stack: Double pointer to the stack
 *
 * Return: None
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
