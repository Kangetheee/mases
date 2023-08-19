#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void forkstr(char *command, char **env) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        perror("fork() fail");
        exit(1);
    } else if (pid == 0) {
	char *argv[2];
	argv[0] = command;
	argv[1] = NULL;
        execve(command, argv, env);
        
        perror("Error");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(void) {
    char *buffer = NULL;
    size_t n = 0;
    ssize_t rline;
    char prompt[] = "#cisfun$ ";
    
    while (1) {
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
        
        rline = getline(&buffer, &n, stdin);
        
        if (rline == -1) {
            free(buffer);
            exit(0);
        }

        if (rline > 0 && buffer[rline - 1] == '\n') {
            buffer[rline - 1] = '\0';
        } 
        forkstr(buffer, NULL);
    }
    
    free(buffer);
    return 0;
}
