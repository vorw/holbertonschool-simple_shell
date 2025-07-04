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
int handle_builtins(char **args, char *input);
void execute_command(char **args, char *program_name);
char *getenv_path(char *command);

#endif /* SHELL_H */
