#include "main.h"

/**
 * prints a pathlist linked list
 * 
 * return void
*/
void printPathList(path_list *head){

    path_list *temp = head;

    while (temp)
    {
        /* code */
        puts(temp->dir_node);
        temp = temp->next;
    }
    
}