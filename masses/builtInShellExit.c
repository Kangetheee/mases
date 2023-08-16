#include "shell.h"

/**
 * shellExit - Exit the shell.
 *
 * Return: " ".
 */
void shellExit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}
	freeTokens(args);
	freeLastInput();
	exit(status);
}
