#include "shell.h"

/**
 * _printShell - Print a string followed by a newline to the standard output.
 *
 * @command: The string to be printed.
 */

void	_printShell(char *command)
{
	if (write(1, command, _strlen(command)) == -1)
	{
		perror("write");
		exit(1);
	}

	if (write(1, "\n", 1) == -1)
	{
		perror("write");
		exit(1);
	}
}




