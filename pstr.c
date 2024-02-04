
#include "monty.h"

/**
 * pstr - Print the string starting at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: None
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL && temp->n != 0 && isascii(temp->n))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
