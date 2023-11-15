#include "shell.h"

/**
 *env - prints current_environ
 *@tokenized_command: command inputed
 *
 *Return: void
 */

void env(char **tokenized_command __attribute__((unused)))
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		print(environ[j], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * quit - leaves the shell
 * @tokenized_command: command inputed
 *
 * Return: void
 */

void quit(char **tokenized_command)
{
	int numb_token = 0, arg;

	for (; tokenized_command[numb_token] != NULL; numb_token++)
		;
	if (numb_token == 1)
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(status);
	}
	else if (numb_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_command[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_command);
			free(commands);
			exit(arg);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
