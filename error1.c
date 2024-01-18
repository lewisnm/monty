#include "monty.h"

int usage_issue(void);
int malloc_issue(void);
int file_open_err(char *filename);
int op_unknown(char *opcode, unsigned int no_line);
int not_int(unsigned int no_line);

/**
 * usage_issue - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_issue(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_issue - Prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int malloc_issue(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * file_open_err - Prints file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int file_open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * op_unknown - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @no_line: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int op_unknown(char *opcode, unsigned int no_line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		no_line, opcode);
	return (EXIT_FAILURE);
}

/**
 * not_int - Prints invalid pushf argument error messages.
 * @no_line: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int not_int(unsigned int no_line)
{
	fprintf(stderr, "L%u: usage: push integer\n", no_line);
	return (EXIT_FAILURE);
}
