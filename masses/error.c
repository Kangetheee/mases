#include "shell.h"

/**
 * puts - Prints a string to the standard output stream
 *
 * Return: Void
 */
void puts(char *str)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(str);
	num_written = write(STDOUT_FILENO, str, len);
	if (num_written == -1)
	{
		perror("write");
	}
}

/**
 * _puterror - Prints an error message to the standard error stream
 *
 * Return: Void
 */
void _puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
