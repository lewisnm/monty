#include "monty.h"

void pushf(stack_t **stack, unsigned int no_line);
void pallf(stack_t **stack, unsigned int no_line);
void pinf(stack_t **stack, unsigned int no_line);
void popf(stack_t **stack, unsigned int no_line);
void swapf(stack_t **stack, unsigned int no_line);

/**
 * pushf - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void pushf(stack_t **stack, unsigned int no_line)
{
	stack_t *temp, *newNode;
	int i;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		append_error(malloc_issue());
		return;
	}

	if (ops_token[1] == NULL)
	{
		append_error(not_int(no_line));
		return;
	}

	for (i = 0; ops_token[1][i]; i++)
	{
		if (ops_token[1][i] == '-' && i == 0)
			continue;
		if (ops_token[1][i] < '0' || ops_token[1][i] > '9')
		{
			append_error(not_int(no_line));
			return;
		}
	}
	newNode->n = atoi(ops_token[1]);

	if (modeCheck(*stack) == STACK) /* STACK mode insert at front */
	{
		temp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = temp;
		if (temp)
			temp->prev = newNode;
		(*stack)->next = newNode;
	}
	else /* QUEUE mode insert at end */
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		newNode->prev = temp;
		newNode->next = NULL;
		temp->next = newNode;
	}
}

/**
 * pallf - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void pallf(stack_t **stack, unsigned int no_line)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)no_line;
}

/**
 * pinf - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void pinf(stack_t **stack, unsigned int no_line)
{
	if ((*stack)->next == NULL)
	{
		append_error(pint_fail(no_line));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * popf - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void popf(stack_t **stack, unsigned int no_line)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		append_error(pop_fail(no_line));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swapf - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @no_line: The current working line number of a Monty bytecodes file.
 */
void swapf(stack_t **stack, unsigned int no_line)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		append_error(few_elements(no_line, "swap"));
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
