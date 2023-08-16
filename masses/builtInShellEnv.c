#include "shell.h"

/**
 * shellEnv - Prints all the environment variables.
 *
 * Return: void.
 */
int shellEnv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}
