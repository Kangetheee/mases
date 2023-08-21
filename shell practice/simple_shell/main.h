i#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/*header files*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>


typedef struct path_list
{
    /* data */
    char *dir_node;
    struct path_list *next;
} path_list;

/*functions*/

char **tokenize (  char *str, const char *delim);
char *getEnv(const char *name); 
char *getEnvfull(const char *name);
void printPath( void);
char **path_ptrs(void);
path_list *buildList(char **ptr);
void freeList(path_list *head, int tok);
int setEnv(const char *name, const char *value, int overwrite);
void printPathList(path_list *head);

#endif /*MAIN_H*/
