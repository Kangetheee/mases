 #include "shell.h"

/**
 * checkForBuiltIn - checks if the command is a built in
 *
 * Return: 1 if command is a built in, 0 otherwise
 */
int checkForBuiltIn(char **args)
{
	if (!args[0])
		return (0);
	if (!strcmp(args[0], "Exit"))
		shellExit(args);
	else if (!strcmp(args[0], "Env"))
		shellEnv();
	else if (!strcmp(args[0], "Setenv"))
		shellSetenv(args);
	else if (!strcmp(args[0], "UnSetenv"))
		shellUnSetenv(args);
	else if (!strcmp(args[0], "Help"))
		shellHelp();
	else if (!strcmp(args[0], "cd"))
		shellCd(args);
	else if (!strcmp(args[0], "Clear"))
		shellClear(args);
	else
		return (0);
	return (1);
}
