#include "monty.h"
#include <string.h>

void clearStack(stack_t **stack);
int start_stack(stack_t **stack);
int modeCheck(stack_t *stack);

/**
 * clearStack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void clearStack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * start_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int start_stack(stack_t **stack)
{
	stack_t *k;

	k = malloc(sizeof(stack_t));
	if (k == NULL)
		return (malloc_issue());

	k->n = STACK;
	k->prev = NULL;
	k->next = NULL;

	*stack = k;

	return (EXIT_SUCCESS);
}

/**
 * modeCheck - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int modeCheck(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
