#include "monty.h"

/**
 * rotl - Rotate the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
