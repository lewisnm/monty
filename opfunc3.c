#include "monty.h"

void nopf(stack_t **stack, unsigned int no_line);
void pchaf(stack_t **stack, unsigned int no_line);
void pstrf(stack_t **stack, unsigned int no_line);

/**
 * nopf - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void nopf(stack_t **stack, unsigned int no_line)
{
	(void)stack;
	(void)no_line;
}

/**
 * pchaf - Prints the character in the top value
 *               node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void pchaf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL)
	{
		append_error(err_pchar(no_line, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		append_error(err_pchar(no_line,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * pstrf - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void pstrf(stack_t **stack, unsigned int no_line)
{
	stack_t *temp = (*stack)->next;

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");

	(void)no_line;
}
