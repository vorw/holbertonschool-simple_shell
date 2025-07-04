#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **tokenize(char *input);
void free_args(char **args);
int handle_builtin(char **args, char *input, int last_status);
void execute_command(char **args, char *program_name, int *last_status);
char *getenv_path(char *command);

#endif /* SHELL_H */
