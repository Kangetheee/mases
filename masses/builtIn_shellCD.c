#include "shell.h"

/**
 * shellCd - changes the current working directory of the shell
 */
void shellCd(char **args)
{
	char *dir = args[1];
	int retu;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = getEnv("HOME");
		if (dir == NULL)
		{
			puts("cd: No HOME directory found\n");
			return;
		}
	}

	retu = chdir(dir);
	if (retu == -1)
	{
		perror("!cd!");
	}
}
