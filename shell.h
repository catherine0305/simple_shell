#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define DELIM " \t\n"

extern char **environ;

char *read_line(void);
char **token(char *line);
int exec(char **cmd, char **argv, int index);
char *_getenv(char *variable);
char *_getpath(char *cmd);

int main(int ac, char **argv);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void freearray(char **array);
void printerror(char *name, char *cmd, int index);
char *_itoa(int n);
void reverse_string(char *str, int len);

int is_builtin(char *cmd);
void handle_builtin(char **cmd, char **argv, int *stat, int index);
void exit_shell(char **cmd, char **argv, int *stat, int index);
void print_env(char **cmd, int *stat);

int is_positive(char *str);
int _atoi(char *str);

#endif
