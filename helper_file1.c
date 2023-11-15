#include "shell.h"

/**
 *_strcmp - Compare two strings
 *@first: first string to compare
 *@second: second string to compare
 *
 * Return: difference btw the two strings
 */

int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 *_strcat - Concatenates two strings
 *@destination: string to concatenate to
 *@source:  string to concatenate
 *
 * Return: address of new
 */

char *_strcat(char *destination, char *source)
{
	char *new =  NULL;
	int length_dest = _strlen(destination);
	int length_source = _strlen(source);

	new = malloc(sizeof(*new) * (length_dest + length_source + 1));
	_strcpy(destination, new);
	_strcpy(source, new + length_dest);
	new[length_dest + length_source] = '\0';
	return (new);
}

/**
 *_strspn - Gets the length of a prefix substring
 *@str1: string to searche
 *@str2: string to use
 *
 *Return: num of bytes in the initial segment of 5 which are part of accept
 */

int _strspn(char *str1, char *str2)
{
	int i = 0;
	int mat = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		mat++;
		i++;
	}
	return (mat);
}

/**
 *_strcspn - Computes segment of str1 which
 *consists of characters not in str2
 *@str1: string to search
 *@str2: string to use
 *
 *Return: index at which a char in str1 exists in str2
 */


int _strcspn(char *str1, char *str2)
{
	int length = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		length++;
	}
	return (length);
}


/**
 *_strchr - Locates a char in a string
 *@s: string to search
 *@c: char to check
 *
 *Return: pointer to the first occurence of c in s
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != c && s[i] != '\0'; i++)
		;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
