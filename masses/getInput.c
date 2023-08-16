#include "shell.h"

static char *lastInput;
/**
 * getInput - Read the line of input from user.

 * Return: Pointer to a buffer containing the user's input.
*/
char *getInput(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nRead;

	do {
		/* print shell prompt */
		prompt();

		/* get a line of input from user */
		nRead = getline(&input, &input_size, stdin);

		/* check for EOF  */
		if (nRead == -1)
		{
			free(input);
			puts("\n");
			return (NULL);
		}

		/* remove trailing newline character */
		input[nRead - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	/* update lastInput to point to the new input */
	lastInput = input;
	return (input);
}

/**
 * freeLastInput - Frees the most recent input entered by the user.
 *
 * This function frees the memory allocated for the most recent input string
 * entered by the user. It should be called after the input string is no longer
 * needed.
 */
void freeLastInput(void)
{
	free(lastInput);
	lastInput = NULL;
}
