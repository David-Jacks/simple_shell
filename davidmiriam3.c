#include "shell.h"

/**
 * _printEnvironment - Print the environment variables to the standard output.
 */

void	_printEnvironment(void)
{
	char	**env;
	int		i;

	i = 0;

	env = environ;

	while (*env != NULL)
	{
		_printShell(env[i]); /*printf("%s\n, env[i])*/
		env++;
	}
}

/**
 * _strcat - Concatenate two strings.
 *
 * @destination: The buffer to concatenate the strings into.
 * @source: The string to be concatenated.
 */

void	_strcat(char *destination, char *source)
{
	int	i;
	size_t	destLength;

	destLength = strlen(destination);
	for (i = 0; source[i] != '\0'; i++)
	{
		/* code */
		destination[destLength + i] = source[i];
	}
	destination[destLength + i] = '\0';

}

/**
 * _strcpy - Copy a string from source to destination.
 * @destination: The destination buffer where the string will be copied.
 * @source: The source string to be copied.
 */
void	_strcpy(char *destination, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}

	destination[i] = '\0';

}

/**
 * _strdup - Duplicate a string.
 *
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the newly allocated duplicated string.
 */


char	*_strdup(char *str)
{
	int		i;
	size_t		strLength;
	char	*dupString;


	if (str == NULL)
	{
		exit(EXIT_FAILURE);
	}
	strLength = _strlen(str);
	dupString = malloc(strLength + 1);
	if (dupString == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		/* code */
		dupString[i] = str[i];
	}
	dupString[strLength] = '\0';
	return (dupString);
}


/*******************************************************/


/**
 * _strcmp - Compare two strings.
 *
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: An integer less than, equal to,
 * or greater than zero if str1 is found,
 * respectively, to be less than,
 * to match, or be greater than str2.
 */

int	_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/*******************************************************/

