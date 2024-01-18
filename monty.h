#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **ops_token;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int no_line);
} instruction_t;

/*stack manipulaion code prototypes*/
void clearStack(stack_t **stack);
int start_stack(stack_t **stack);
int modeCheck(stack_t *stack);
void clear_token(void);
unsigned int tkn_len(void);
int init_monty(FILE *script_fd);

/*error code appendage*/
void append_error(int error_code);

/*opcode function prototypes*/
void pushf(stack_t **stack, unsigned int no_line);
void pallf(stack_t **stack, unsigned int no_line);
void pinf(stack_t **stack, unsigned int no_line);
void popf(stack_t **stack, unsigned int no_line);
void swapf(stack_t **stack, unsigned int no_line);
void addf(stack_t **stack, unsigned int no_line);
void nopf(stack_t **stack, unsigned int no_line);
void subf(stack_t **stack, unsigned int no_line);
void divf(stack_t **stack, unsigned int no_line);
void mulf(stack_t **stack, unsigned int no_line);
void modf(stack_t **stack, unsigned int no_line);
void pchaf(stack_t **stack, unsigned int no_line);
void pstrf(stack_t **stack, unsigned int no_line);
void rot1f(stack_t **stack, unsigned int no_line);
void rotf(stack_t **stack, unsigned int no_line);
void stackf(stack_t **stack, unsigned int no_line);
void queuef(stack_t **stack, unsigned int no_line);

char **strtow(char *str, char *delims);
char *get_int(int n);

/*error function prototypes*/
int usage_issue(void);
int malloc_issue(void);
int file_open_err(char *filename);
int op_unknown(char *opcode, unsigned int no_line);
int not_int(unsigned int no_line);
int pop_fail(unsigned int no_line);
int pint_fail(unsigned int no_line);
int few_elements(unsigned int no_line, char *op);
int dvsn_err(unsigned int no_line);
int err_pchar(unsigned int no_line, char *message);


#endif/*MONTY_H*/
