#include "shell.h"

/**
 * getPath - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */
char *getPath(void)
{
	return (getEnv("PATH"));
}
