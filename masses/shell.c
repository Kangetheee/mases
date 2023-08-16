#include "shell.h"

/**
 * main - implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	char **args;
	int status;

	/* Register signal handlers */
	signal(SIGINT, handleSigint);
	signal(SIGQUIT, handleSigquit);
	signal(SIGTSTP, handleSigstp);

	do {
		input = getInput();
		if (!input || !*input)/* EOF detected, exit the loop */
			break;

		args = tokenizeInput(input);
		if (!args || !*args)
		{
			free(input);
			freeTokens(args);
			continue;
		}
		status = execute(args);
		free(input);
		freeTokens(args);

		/* Set status to 1 to continue the loop */
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
