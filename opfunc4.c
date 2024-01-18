#include "monty.h"

void rot1f(stack_t **stack, unsigned int no_line);
void rotf(stack_t **stack, unsigned int no_line);
void stackf(stack_t **stack, unsigned int no_line);
void queuef(stack_t **stack, unsigned int no_line);

/**
 * rot1f - Rotates the first value of a stack_t linked list to the last.
 * @stack: A pointer to the first mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void rot1f(stack_t **stack, unsigned int no_line)
{
	stack_t *first, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	first = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	first->next->prev = *stack;
	(*stack)->next = first->next;
	last->next = first;
	first->next = NULL;
	first->prev = last;

	(void)no_line;
}

/**
 * rotf - Rotates the last value of a stack_t linked list to the first.
 * @stack: A pointer to the first mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void rotf(stack_t **stack, unsigned int no_line)
{
	stack_t *first, *last;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	first = (*stack)->next;
	last = (*stack)->next;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	(*stack)->next = last;
	last->prev = *stack;
	last->next = first;
	first->prev = last;

	(void)no_line;
}

/**
 * stackf - Converts a queue to a stack.
 * @stack: A pointer to the first mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void stackf(stack_t **stack, unsigned int no_line)
{
	(*stack)->n = STACK;
	(void)no_line;
}

/**
 * queuef - Converts a stack to a queue.
 * @stack: A pointer to the first mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void queuef(stack_t **stack, unsigned int no_line)
{
	(*stack)->n = QUEUE;
	(void)no_line;
}
