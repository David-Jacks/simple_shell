#ifndef HEADER_H
#define HEADER_H
/*libray headers*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_TOKEN 1024
extern char **environ;

/*main functions**/
int _hasPathSeprator(char *command);
char *_getUserInput(void);
char **_getInputTokenize(char *input);
char *_constructShell(char *input);
char *_getenv(const char *env);
void _execute(char *command, char **args);
void _executeShell(char *command, char **args);
void _printCommandNotFound(char *erroMessage);

/****HELPING FUNCITONS****/
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
void _strcpy(char *destination, char *source);
void _printEnvironment(void);
void _putchar(char c);
void _printShell(char *command);
void _strcat(char *destination, char *source);
void _freeArgs(char **args);
char *_printString(char *str);
char *_strdup(char *str);
ssize_t _getline(char **line, size_t *len, FILE *stream);
#endif

