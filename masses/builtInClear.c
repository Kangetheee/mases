#include "shell.h"

/**
 * shellClear - clears the terminal screen.
 * @args: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/
int shellClear(char **args)
{
	(void)args; /* avoid "unsued parameter" warning */
	puts("\033[2J\033[H");
	return (1);
}
