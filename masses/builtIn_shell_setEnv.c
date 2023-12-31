#include "shell.h"

/**
 * shellSetenv - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */
int shellSetenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_puterror("Usage: SetEnv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		_puterror("SetEnv");
		return (-1);
	}
	return (0);
}

/**
 * shellUnSetenv - Unset an environment variable
 * @args name of the environment variable
 *
 * Return: Nothing
 */
int shellUnSetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_puterror("Usage: UnSetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puterror("UnSetenv");
	}
	return (0);
}
