#include "main.h"

/**
 * tokenize strings
 * return array of tokens
 * 
*/
char **tokenize(char *str, const char *delim){
    char *token;
    char **ret = NULL;
    int i = 0;

    token = strtok(str, delim);
    while(token){
        ret = realloc(ret, sizeof(char *)* (i+1));
        if(ret == NULL)
          dprintf(2, "Error: realloc() failure\n"),exit(EXIT_FAILURE);
          
    strcpy(ret[i],token);
    token = strtok(NULL,delim);
    i++;

    /*increase size of array*/

    ret = realloc(ret,(i+1)* sizeof(char *));
    if(!ret)
      dprintf(2, "Error: realloc() failure\n"), exit(EXIT_FAILURE);
    }

    ret[i] = NULL;
    return(ret);
}

#if 0
/**
 * main- entry point
 * 
 * EXIT_SUCCESS
*/
int main(void){
    char str []= "Noah:Mburu\n";
    char **arr = tokenize(str, ":");
    int i;

    for(i=0; arr[i]; i++){
        if(arr[i+1] == NULL){
            printf("%s",arr[i]);
        }
        else
            puts(arr[1]);
    }
    for(i=0; arr[i]; i++)
        free(arr[i]);
    free(arr);

    exit(EXIT_SUCCESS);
}
#endif