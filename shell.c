#include "shell.h"
int main(void);
/**
 * main - Entry point for the custom shell program.
 * This function initializes variables, continuously
 * prompts the user for input,
 * tokenizes the input, and executes the corresponding
 * shell command until the
 * program is manually terminated by the user.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{

	char *input;

	char **args;

	char *fullPath;
	char *command;
	int i = 0;

	do {
		input = _getUserInput();
		args = _getInputTokenize(input);
		command = args[0];

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				_printShell("Goodbye");
				free(input);
				_freeArgs(args);
				exit(0);
			}
			else if (strcmp(command, "env") == 0)
			{
				_printEnvironment();
			}
			else if (_hasPathSeprator(command))
			{
				if (access(command, X_OK) == 0)
				{
					_execute(command, args);
				}
				else
				{
					_printCommandNotFound(command);
				}
			}
			else
			{
				fullPath = _constructShell(command);

				if (fullPath != NULL)
				{
					_execute(fullPath, args);
					free(fullPath);
				}
				else
				{
					_printCommandNotFound(command);
				}
			}
		}
		free(input);

		for (i = 0; args[i] != NULL; ++i)
		{
			free(args[i]);
		}
		free(args);
	} while (1);
	return (0);
}

