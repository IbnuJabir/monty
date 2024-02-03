#include "monty.h"

/**
 * pop - Remove the top element of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 *
 * Return: None
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
	arg = NULL;
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free_stack(stack);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    free(*stack);
    *stack = temp;
}
