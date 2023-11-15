#include "shell.h"

/**
 * tokenizer -Tokenizes input and stores it into an array
 *@input_string: input to be parsed
 *@delim: delimiter, needs to be one character string
 *
 *Return: array of tokens
 */

char **tokenizer(char *input_string, char *delim)
{
	int numb_delim = 0;
	char **av = NULL;
	char *tokn = NULL;
	char *save_ptr = NULL;

	tokn = _strtok_r(input_string, delim, &save_ptr);

	while (tokn != NULL)
	{
		av = _realloc(av, sizeof(*av) * numb_delim, sizeof(*av) * (numb_delim + 1));
		av[numb_delim] = tokn;
		tokn = _strtok_r(NULL, delim, &save_ptr);
		numb_delim++;
	}

	av = _realloc(av, sizeof(*av) * numb_delim, sizeof(*av) * (numb_delim + 1));
	av[numb_delim] = NULL;

	return (av);
}

/**
 *print - Prints a string to stdout
 *@string: string to be printed out
 *@stream: stream to print to
 *
 *Return: void, return ntn
 */
void print(char *string, int stream)
{
	int j = 0;

	for (; string[j] != '\0'; j++)
		write(stream, &string[j], 1);
}

/**
 *remove_newline - Removes new line from a string
 *@str: string used
 *
 *
 *Return: void
 */

void remove_newline(char *str)
{
	int j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			break;
		j++;
	}
	str[j] = '\0';
}

/**
 *_strcpy - Copies a string to another buffer
 *@source: source to be copied from
 *@dest: destina to copy to
 *
 * Return: void
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 *_strlen - Counts string length
 *@string: text to be counted
 *
 * Return: length of string
 */

int _strlen(char *string)
{
	int length = 0;

	if (string == NULL)
		return (length);
	for (; string[length] != '\0'; length++)
		;
	return (length);
}
