#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tok.c"

int main(void)
{
	char *arg = NULL; ///array of pointer is empty
	char **argv; //pointer to char
	size_t len = 0; //unsigned size of char for the object(initialized}
	ssize_t nRead; // variable to to store char read
	pid_t process;
	int status, i;
	
	printf("$ ");
	while((nRead = getline(&arg, &len, stdin)) != -1) //loop breaks if userinput is zero
	{
		if (strcmp(arg, "exit\n") == 0) //if string is empty the program breaks
			break;
		arg[nRead - 1] = '\0';//remove trailing space
		argv = tokenize(arg, " ");
		if ((process = fork()) == -1)
		{
			perror("Error");
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(arg);
			exit(EXIT_FAILURE);
		}
		if (process == 0)
		{

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				for (i = 0; argv[i]; i++)
					free(argv[i]);
				free(argv);
				free(arg);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			printf("$ ");
		}
	}
	free(arg);
	exit(EXIT_SUCCESS);
}
