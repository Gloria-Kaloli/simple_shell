#include "shell.h"

/**
 * non_interactive - handles non_interactive mode
 *
 * Return:non_interactive mode for the shell
 */

void non_interactive(void)
{
	char **current = NULL;
	int i, type_command = 0;
	size_t n = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &n, stdin) != -1)
		{
			remove_newline(line);
			remove_comment(line);
			commands = tokenizer(line, ";");
			for (i = 0; commands[i] != NULL; i++)
			{
				current = tokenizer(commands[i], " ");
				if (current[0] == NULL)
				{
					free(current);
					break;
				}
				type_command = parse_command(current[0]);
				initializer(current, type_command);
				free(current);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
