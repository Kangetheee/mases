#include "main.h"

int main(int argc, char *argv){
    char *line = NULL, *tmp = NULL;
    size_t len = 0;
    ssize_t nRead;
    int i;

    if (argc != 1){
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("$ ");
    while ((nRead = getline(&line, &len, stdin)) != -1)
    {
        /* code */
        if(strcmp(line, "exit\n")==0){
            free(line);
            exit(EXIT_SUCCESS);
        }
        if(nRead == 1 && line[0] == 10){
            printf("$ ");
            continue;
        }
        if (line[nRead - 2] == '\\'){
            printf("> ");
            tmp = malloc(nRead);
            if (tmp == NULL)
                exit(EXIT_FAILURE);
            for (i=0; i < strlen(tmp); i++){
                if ((tmp[1]== 92) && (tmp[i-1] != 92))
                    continue;
                putchar(tmp[i]);
            }
            free(tmp);
            tmp = NULL;
        }
        fwrite(line,1,nRead,stdout);
        printf("$ ");
    }
    free(line);
    putchar(10);
    exit(EXIT_SUCCESS);
    
}
