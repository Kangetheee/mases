#include "main.h"
#include "tok.c"
#include "getEnv.c"

/**
 * print each directory contained in $PATH
 * EXIT_SUCCESS
*/

void printPath(void){
    char *path = getEnv("PATH");
    char *str = path;
    char **dir = tokenize(str, ":");
    unsigned int i;

    if(!(path))
       dprintf(2, "$PATH NOT FOUND!\n"), exit(EXIT_FAILURE);
    for( i=0; dir[i]; i++){
        puts(dir[i]);
        free(dir[i]);
    }
    free(dir);
}

int main(void){
    printPath();
    exit(EXIT_SUCCESS);
}