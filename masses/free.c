#include "shell.h"

/**
 * freeError - frees alloc'd pointers following system error
 *
 * Return: void.
 */
void freeError(char **argv, char *arg)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(arg);
	exit(EXIT_FAILURE);
}

/**
 * freeTokens - frees memory allocated dynamically by tokenize()
 *
 * Return: void.
 */
void freeTokens(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free((ptr[i]));
	free(ptr);
}


/**
 * freePath - Frees the global variable containing the PATH environment
 *              variable value
 *
 * Return: Nothing
 */
void freePath(void)
{
	if (environ != NULL)
	{
		size_t i = 0;

		while (environ[i] != NULL)
		{
			if (_strncmp(environ[i], "PATH=", 5) == 0)
			{
				free(environ[i]);
				environ[i] = NULL;
				break;
			}
			i++;
		}
	}
}
