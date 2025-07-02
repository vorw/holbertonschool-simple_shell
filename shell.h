#ifndef SHELL_H
#define SHELL_H
/*
 * File: shell.h
 * Desc: Prototypes and libraries for a simple shell program.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>


/* Access to environment variables */
extern char **environ;

/**
 * tokenize - Splits a line into words
 * @line: The input line to split
 * @args: The resulting array of words
 *
 * Description: Tokenizes the input line into separate words.
 * This function fills the args array with each word from line.
 */
void tokenize(char *line, char **args);


/**
 * execute_command - Executes a given command
 * @args: Array of command and its arguments
 *
 * Description: Creates a child process and executes the command
 * using execve. Parent waits for the child to finish.
 * Return: Exit status of the executed command,
 *         127 if command not found,
 *         1 if fork or execve fails.
 */
int execute_command(char **args);


/**
 * get_path_from_environ - Gets the value of PATH from environment variables
 *
 * Return: Pointer to the value after "PATH=", or NULL if not found
 */
char *get_path_from_environ(void);


/**
 * find_path - Looks for a command inside PATH directories
 * @command: The name of the command (e.g. "ls")
 *
 * Return: Full path of the command if found, or NULL if not found
 */
char *find_path(char *command);



/**
 * handle_exit_env - Handles built-in commands: exit and env
 * @args: Array of command and its arguments
 * @line: The input line (to free if exiting)
 * @status: Pointer to status variable to exit with
 *
 * Return: 1 if built-in command was handled, 0 otherwise
 */
int handle_exit_env(char **args, char *line, int *status);



#endif /* SHELL_H */
