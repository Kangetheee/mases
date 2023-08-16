#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*my macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* prompt.c */
void prompt(void);

/* getInput.c */
char *getInput(void);
void freeLastInput(void);
/* getLine.c*/
void *getline(void);

/* builtIn functions */
int checkForBuiltIn(char **args);
int execute_buitlin(char *cmd, char **args);
void shellHelp(void);
void shellExit(char **args);
void shellCd(char **args);
int shellSetenv(char **args);
int shellUnSetenv(char **args);
int shellEnv(void);
int shellClear(char **args);

/* handleSignal.c */
void handleSigint(int sign);
void handleSigquit(int sign);
void handleSigstp(int sign);

/* exec.c */
int exec(char **args);

/* parse.c */
char **tokenize(char *str, const char *delim);
char **tokenizeInput(char *input);

/* envMain.c */
char *getEnv(const char *name);

/* getPath.c */
char *getPath(void);

/* findPath.c */
char *findPath(char *command);

/* free.c */
void freeError(char **argv, char *arg);
void freeTokens(char **ptr);
void freePath(void);

/* error.c */
void puts(char *str);
void _puterror(char *err);

/* util1.c */
int strlen(const char *);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strstr(char *haystack, char *needle);
char *strchr(char *s, char c);

/* utils_funcs2.c */
char *strcpy(char *, char *);
char *strcat(char *, const char *);
char *strdup(const char *);
int _putchar(char);
unsigned int strspn(char *s, char *accept);

/* utils_funcs3.c */
int atoi(const char *str);
char *memset(char *, char, unsigned int);
char *memcpy(char *dest, char *src, unsigned int n);
void *realloc(void *, unsigned int, unsigned int);
void *calloc(unsigned int nmemb, unsigned int size);



#endif
/* SHELL_H_INCLUDED*/
