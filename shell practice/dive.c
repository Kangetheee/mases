#include "main.h"
#include "tok.c"
#define MAX_PATH_LENGTH 100 /*Maximum length of the custom path*/

int main(void)
{
	char *arg = NULL; /*array of pointer is empty*/
	char **argv; /*pointer to char*/
	size_t len = 0; /*unsigned size of char for the object(initialized)*/
	ssize_t nRead; /*variable to to store char read*/
	pid_t process;
	int status, i;
	
	printf("$ ");
	while((nRead = getline(&arg, &len, stdin)) != -1) /*loop breaks if userinput is zero*/
	{
		if (strcmp(arg, "exit\n") == 0) /*if string is empty the program breaks*/
			break;
		arg[nRead - 1] = '\0';/*remove trailing space*/
		argv = tokenize(arg, " ");

		char customPath[MAX_PATH_LENGTH];
                printf("Enter custom path for commands: ");
                fgets(customPath, sizeof(customPath), stdin);
                customPath[strlen(customPath) - 1] = '\0'; /*Remove newline*/
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
			/*Construct the full command path using the custom path*/
            		char commandPath[MAX_PATH_LENGTH + strlen(argv[0]) + 2]; /* +2 for '/' and '\0'*/
            		snprintf(commandPath, sizeof(commandPath), "%s/%s", customPath, argv[0]);
			if (execve(commandPath, argv, NULL) == -1)
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
