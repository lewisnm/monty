#include "monty.h"

void clear_token(void);
unsigned int tkn_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int init_monty(FILE *script_fd);

/**
 * clear_token - Frees the global ops_token array of strings.
 */
void clear_token(void)
{
	size_t i = 0;

	if (ops_token == NULL)
		return;

	for (i = 0; ops_token[i]; i++)
		free(ops_token[i]);

	free(ops_token);
}

/**
 * tkn_len - Gets the length of current ops_token.
 *
 * Return: Length of current ops_token (as int).
 */
unsigned int tkn_len(void)
{
	unsigned int toks_len = 0;

	while (ops_token[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", pushf},
		{"pall", pallf},
		{"pint", pinf},
		{"pop", popf},
		{"swap", swapf},
		{"add", addf},
		{"nop", nopf},
		{"sub", subf},
		{"div", divf},
		{"mul", mulf},
		{"mod", my_modf},
		{"pchar", pchaf},
		{"pstr", pstrf},
		{"rotl", rot1f},
		{"rotr", rotf},
		{"stack", stackf},
		{"queue", queuef},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * init_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int init_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int no_line = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (start_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		no_line++;
		ops_token = strtow(line, DELIMS);
		if (ops_token == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			clearStack(&stack);
			return (malloc_issue());
		}
		else if (ops_token[0][0] == '#') /* comment line */
		{
			clear_token();
			continue;
		}
		op_func = get_op_func(ops_token[0]);
		if (op_func == NULL)
		{
			clearStack(&stack);
			exit_status = op_unknown(ops_token[0], no_line);
			clear_token();
			break;
		}
		prev_tok_len = tkn_len();
		op_func(&stack, no_line);
		if (tkn_len() != prev_tok_len)
		{
			if (ops_token && ops_token[prev_tok_len])
				exit_status = atoi(ops_token[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			clear_token();
			break;
		}
		clear_token();
	}
	clearStack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_issue());
	}

	free(line);
	return (exit_status);
}
