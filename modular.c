#include "shell.h"



/**
 * _getUserInput - Get user input from stdin.
 *
 * Return: A pointer to the input string.
 */

char *_getUserInput(void)
{
	char *input;

	size_t inputLength;

	ssize_t nread;

	input = NULL;

	inputLength = 0;

	_printString("Kel&Afia$ ");

	nread = _getline(&input, &inputLength, stdin);

	if (nread == -1)
	{
		_printString("\nGoodbye!\n");
		exit(EXIT_SUCCESS);
	}

	return (input);
	/* Memory allocated for input will be freed in the calling function*/
}

/**
 * _getInputTokenize - Tokenize the input string.
 * @input: The input string to be tokenized.
 *
 * Return: An array of tokens.
 */

char **_getInputTokenize(char *input)
{
	char *token;

	char **args;

	int i;

	char *delimiter = " \n\t\r\a";
	args = malloc(sizeof(char *) * MAX_TOKEN);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;

	token = strtok(input, delimiter);
	while (token != NULL && i < MAX_TOKEN - 1)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delimiter);

		i++;
	}
	args[i] = NULL;
	return (args);
  /* Memory allocated for args will be freed in the calling function*/
}

/**
 * _execute - Execute a shell command.
 * @command: The command to be executed.
 * @args: Array of arguments for the command.
 */

void _execute(char *command, char **args)
{
	pid_t childPid;

	int status;

	status = 0;

	childPid = fork();
	if (childPid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(&status);
	}
}


char *_constructShell(char *input);


/**
 * _constructShell - Construct the path to the command.
 * @input: The command input.
 *
 * Return: A pointer to the constructed path.
 */





char *_constructShell(char *input)
{
	char *delimeter;

	char *path;

	char *pathCpy;

	char *token;


	size_t inputLength;

	size_t tokenLength;

	char *fullPath;

	char *symbol;

	delimeter = ":";

	path = _getenv("PATH");

	if (path == NULL)

	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	pathCpy = _strdup(path);

	if (pathCpy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(pathCpy, delimeter);

	while (token != NULL)
	{
		inputLength = _strlen(input); /*Calc the length of the input*/

		tokenLength = _strlen(token); /*Calc the length of the token*/

		fullPath = malloc(tokenLength + inputLength + 2);
		/* allocate memory (+1 for '/', +1 for null terminator)*/

		if (fullPath == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		symbol = "/";
		_strcpy(fullPath, token);
		_strcat(fullPath, symbol);
		_strcat(fullPath, input);
		if (access(fullPath, X_OK) == 0)
		{
			free(pathCpy);
			return (fullPath);
		}
		token = strtok(NULL, delimeter);
		free(fullPath);
	}
	return (NULL);
	free(path);
}


