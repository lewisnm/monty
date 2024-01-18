#include "monty.h"

void addf(stack_t **stack, unsigned int no_line);
void subf(stack_t **stack, unsigned int no_line);
void divf(stack_t **stack, unsigned int no_line);
void mulf(stack_t **stack, unsigned int no_line);
void modf(stack_t **stack, unsigned int no_line);

/**
 * addf - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void addf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	popf(stack, no_line);
}

/**
 * subf - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void subf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	popf(stack, no_line);
}

/**
 * divf - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void divf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		append_error(dvsn_err(no_line));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	popf(stack, no_line);
}

/**
 * mulf - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mulf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	popf(stack, no_line);
}

/**
 * modf - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void modf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		append_error(dvsn_err(no_line));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	popf(stack, no_line);
}
