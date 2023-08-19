#include "main.h"
#include "pathList.c"
#include "getEnvfull.c"

/**
 * custom boilerplate for setenv()
 * 
 * return 0(success)
 * return -1(failure)
*/

int setEnv(const char*name, const char *value, int overwrite){

    char *ptr = getEnvfull(name);
    path_list *head = buildList(environ);
    path_list *temp = head;

    if (ptr){
        if(overwrite == 0)
          return(0);
        else{
            while(1){
                if(!(strcmp(ptr, temp->dir_node))){
                    temp->dir_node = calloc(strlen(value)+ 1,sizeof(char));
                    if(!(temp->dir_node)){
                        dprintf(2, "calloc() failure\n");
                        return(-1);
                    }
                    temp->dir_node = (char *)value;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    else{
        while(temp)
            temp = temp -> next;
        temp = malloc(sizeof(path_list));
        if(!(temp)){
            dprintf(2, "malloc() failure\n");
            return (-1);
        }
        temp->dir_node = (char *)value;
        temp->next = NULL;
    }
    return 0;
}

/**
 * check code
 * return 0
*/
int main(void){
    printf("Before: %s\n", getEnvfull("USER"));
    setEnv("USER", "Noah", 1);
    printf("After: %s\n", getEnvfull("USER"));
    setEnv("EII", "Pointless", 1);
    /*printf("%s\n", getEnvfull("EII"));*/
    return 0;
    
}
