#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a string and seperates its wrds
 *
 * @str: string to seperate into wrds
 * @delims: delimitors to use to delimit wrds
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **wrds = NULL;
	int wordCount, wrdLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wordCount = get_word_count(str, delims);


	if (wordCount == 0)
		return (NULL);
	wrds = malloc((wordCount + 1) * sizeof(char *));
	if (wrds == NULL)
		return (NULL);
	while (i < wordCount)
	{
		wrdLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		wrds[i] = malloc((wrdLen + 1) * sizeof(char));
		if (wrds[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(wrds[i]);
			}
			free(wrds);
			return (NULL);
		}
		n = 0;
		while (n < wrdLen)
		{
			wrds[i][n] = *(str + n);
			n++;
		}
		wrds[i][n] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		i++;
	}
	wrds[i] = NULL; /* last element is null for iteration */
	return (wrds);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit wrds
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pndng = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pndng = 1;
		else if (pndng)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit wrds
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wordCount = 0, pndng = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pndng = 1;
		else if (pndng)
		{
			pndng = 0;
			wordCount++;
		}
		i++;
	}
	return (wordCount);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit wrds
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pndng = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delims))
			pndng = 1;
		else if (pndng)
			break;
		i++;
	}
	return (str + i);
}
