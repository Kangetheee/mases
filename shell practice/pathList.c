#include "main.h"
#include "tok.c"
#include "getEnv.c"

/**
 * pathPtrs - returns arrays of directories in $PATH
*/

char **path_ptrs(void){
    char *path = getEnv("PATH");
    char *str = path;
    char **dir = tokenize(str, ":");
    unsigned int i;

    if (!(path))
        dprintf(2, "$PATH not found!\n"), exit(EXIT_FAILURE);

    return(dir);
}

/**
 * buildList builds a linked list of directories
 * 
 * returns pointer to start
*/

path_list *buildList(char **ptrs){
    int i;
    path_list *head;
    path_list *temp =NULL;

    /*just by the way*/
    if(!(head = malloc(sizeof(path_list))))
       dprintf(2, "malloc() failure\n"),exit(EXIT_FAILURE);
    head->dir_node = ptrs[0];
    head->next = NULL;
    temp = head ;
    for(i=1; ptrs[i]; i++){
        if(!(temp->next = malloc(sizeof(path_list))))
          dprintf(2, "malloc() failure\n"),exit(EXIT_FAILURE);
    temp = temp -> next;
    temp -> dir_node = ptrs[i];
    temp ->next = NULL;
    }
}

/**
 * freeList- frees single linked lists
 * returns void
*/

void freeList(path_list *head, int tok){
    path_list *temp;

    /*char **ptr;*/
    int i;

    //ptr = &(head->dir_node);

    while (head)
    {
        /* code */
        temp = head-> next;
        if(tok)
          free(head->dir_node);
        free(head);
        head = temp;
    }
    //free(ptr);
}

#if 0
/**
 *  main print  linked lists
 * 
 * return 0
*/
int main(void){
    char **ptr = path_ptrs();
    path_list *head = buildList(ptr);
    path_list *temp = head;
    while(temp){
        puts(temp->dir_node);
        temp = temp->next;
    }
    freeList(head, 1);
    return 0;
}
#endif
