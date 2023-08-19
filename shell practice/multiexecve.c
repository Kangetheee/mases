#include "main.h"

/**
 * runs a program in 5 child processes with same parent
*/

int main(void){
    pid_t pid;
    int i, status;

    for(i=0; i<5;i++){
        pid= fork();
        if (pid == -1){
            perror("fork() failure\n");
            exit(EXIT_FAILURE);
        }
        if(pid == 0){
            char *argv[] = {"Habari", NULL};
            if(exec(argv[0], argv, NULL)== -1){
                perror("exec() failure\n");
                exit(EXIT_FAILURE);
            }
        }
        else{
            wait(&status);
        }
    }
    if (pid != 0)
    exit(EXIT_SUCCESS);
}