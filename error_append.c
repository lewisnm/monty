#include "monty.h"

/**
 * append_error - Sets last element of ops_token to be an error code.
 * @error_code: Integer to store as a string in ops_token.
 */
void append_error(int error_code)
{
	int token_len = 0, i = 0;
	char *str_exit = NULL;
	char **new_token = NULL;

	token_len = tkn_len();
	new_token = malloc(sizeof(char *) * (token_len + 2));
	if (!ops_token)
	{
		malloc_issue();
		return;
	}
	while (i < token_len)
	{
		new_token[i] = ops_token[i];
		i++;
	}
	str_exit = get_int(error_code);
	if (!str_exit)
	{
		free(new_token);
		malloc_issue();
		return;
	}
	new_token[i++] = str_exit;
	new_token[i] = NULL;
	free(ops_token);
	ops_token = new_token;
}
