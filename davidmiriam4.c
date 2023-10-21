#include  "shell.h"


/**
 * _hasPathSeprator - Check if a command contains a path separator (/).
 *
 * @command: The command to be checked.
 *
 * Return: 1 if the command contains a path separator, 0 otherwise.
 */


int	_hasPathSeprator(char *command)
{
	return (strchr(command, '/') != NULL);
}

/**
 * _printCommandNotFound - Print an error message for a command not found.
 *
 * @erroMessage: The command that was not found.
 */

void _printCommandNotFound(char *erroMessage)
{
	char *errorMessage;

	char *notFoundMessage;

	errorMessage = "bash: ";
	notFoundMessage = ": command not found\n";
	if (write(2, errorMessage, _strlen(errorMessage)) == -1)
	{
		perror("write");

		exit(EXIT_FAILURE);
	};
	if (write(2, erroMessage, _strlen(erroMessage)) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	};
	if (write(2, notFoundMessage, _strlen(notFoundMessage)) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	};
}


/**
 * _getenv - Get the value of a specific environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: If the environment variable is found, return its value.
 *         If the variable is not found or if @name is NULL, return NULL.
 */
char *_getenv(const char *name)
{
	int i, j;

	char *value;

	if (!name)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		j = 0;

		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);

				return (value);
			}
		}
	}
	return (0);
}

