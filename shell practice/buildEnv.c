#include "main.h"
#include "pathList.c"

path_list *buildenv(void){
    path_list *head = buildList(environ);
    return (head);
}

int main(void){
    path_list *head = buildenv();
    path_list *temp = head;

    while (temp)
    {
        /* code */
        puts(temp->dir_node);
        temp = temp -> next;
    }
    freeList(head,0);
    return 0;
    
}