#include "shell.h"

/**
 * main - Entry point
 *
 * Description:the entry point of the shell
 * Checks command input from users and process it either in interactive mode
 * or in non-interactive mode based on whether the stdin is a TTY
 *
 * Return: 0 (On Success)
 */
int main(void)
{
	size_t size_prompt;

	char *prompt;

	int status;

	size_prompt = 0;

	prompt = NULL;

	status = 0;

	if (!isatty(0))
	{
		while (getline(&prompt, &size_prompt, stdin) != -1)
		{
			nonInteractMode(prompt, &status);
		}
		if (prompt)
		{
			free(prompt);
			prompt = NULL;
		}
		return (status);
	}
	startMyshell();
	return (0);
}
