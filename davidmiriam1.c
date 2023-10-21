#include "shell.h"

/**
 * _putchar - Write a character to the standard output.
 *
 * @c: The character to be written.
 */

void	_putchar(char c)
{
	if ((write(1, &c, 1)) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}



/**
 * _printString - Print a string to the standard output.
 *
 * @str: The string to be printed.
 *
 * Return: A pointer to the null terminator of the input string.
 */


char	*_printString(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

	return (str);
}


/**
 * _strlen - Calculate the length of a string.
 *
 * @str: The input string.
 *
 * Return: The length of the input string.
 */
/**/

size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 *_getline - Read a line from standard input.
 * @line: Pointer to the buffer where the line is stored.
 * @len: Pointer to the size of the buffer.
 * @stream: File stream to read from (usually stdin).
 * Return: Number of characters read (excluding newline), or -1 on failure.
 */

ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	ssize_t bytesRead = getline(&buffer, &bufferSize, stream);

	if (bytesRead != -1)
	{
		if (bytesRead > 0 && buffer[bytesRead - 1] == '\n')
		{
			buffer[bytesRead - 1] = '\0';
			bytesRead--;
		}
		*line = buffer;
	}
	else
	{
		free(buffer);
	}

	*len = bytesRead;
	return (bytesRead);
}

/**
 * _freeArgs - Free memory allocated for an array of strings.
 *
 * @args: The array of strings to be freed.
 */

void	_freeArgs(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; ++i)
	{
		free(args[i]); /*free memory allocated for each token*/
	}
	free(args); /* free the array of token pointers*/
}

