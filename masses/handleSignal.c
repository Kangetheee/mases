#include "shell.h"

/**
 * handleSigint - Signal handler for SIGINT (Ctrl+C)
 *
 * Return: Nothing
 */
void handleSigint(int sign)
{
	(void) sign;
	_putchar('\n');
	prompt();
}

/**
 * handleSigquit - Signal handler for SIGQUIT (Ctrl+\)
 *
 * Return: Nothing
 */
void handleSigquit(int sign)
{
	(void) sign;
	_puterror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handleSigstp - Signal handler for SIGTSTP (Ctrl+Z)
 *
 * Return: Nothing
 */
void handleSigstp(int sign)
{
	(void) sign;
	puts("\n");
	prompt();
}
