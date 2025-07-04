#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **split_line(char *line);
void free_tokens(char **tokens);
int process_builtin(char **tokens, char *line, int status);
void run_command(char **tokens, char *program_name, int *status);
char *resolve_path(char *cmd);

#endif /* SIMPLE_SHELL_H */
