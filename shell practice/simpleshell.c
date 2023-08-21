#include "main.h"
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(){
    char* command = NULL;
    size_t command_size = 0;

    while(1){
        printf("#createwithc$ ");
        if(getline(&command, &command_size, stdin) == -1){
            break;
        }

        /*remove trailing new characters*/
        command[strcspn(command, "\n")] = '\0';

        pid_t pid = fork();
        if (pid == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        } else if(pid == 0){
            /**
            *child
            *parse command
            */

            char* tokens[MAX_COMMAND_LENGTH];
            char* token = strtok(command, " ");
            int i = 0;
            while (token != NULL)
            {
                /* code */
                token[i++] = token;
                token = strtok(NULL, " ");
            }
            tokens[i] = NULL; //set last argument

            //execute command
            if (wait(NULL) == -1){
                perror("Ngoja");
                exit(EXIT_FAILURE);
            }
            
        }
    }
    free(command);
    return 0;
}
