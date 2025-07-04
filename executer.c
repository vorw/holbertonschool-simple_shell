#include "simple_shell.h"

/**
 * run_command - Forks and runs external commands.
 * @tokens: Command + arguments.
 * @program_name: Name of shell.
 * @status: Pointer to store exit status.
 */
void run_command(char **tokens, char *program_name, int *status)
{
	pid_t pid;
	char *cmd_path = NULL;
	struct stat sb;

	if (stat(tokens[0], &sb) == 0)
		cmd_path = tokens[0];
	else
		cmd_path = resolve_path(tokens[0]);

	if (!cmd_path)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, tokens[0]);
		*status = 127;
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(cmd_path, tokens, environ);
		perror(program_name);
		exit(127);
	}
	else if (pid > 0)
		waitpid(pid, status, 0);

	if (cmd_path != tokens[0])
		free(cmd_path);
}

/**
 * resolve_path - Builds the full path of a command using PATH.
 * @cmd: Command name.
 *
 * Return: Full path or NULL.
 */
char *resolve_path(char *cmd)
{
	char *path_val, *dir, *path_cp, *full_cmd;
	struct stat st;

	path_val = getenv("PATH");
	if (!path_val || !*path_val)
		return (NULL);

	path_cp = strdup(path_val);
	if (!path_cp)
		return (NULL);

	dir = strtok(path_cp, ":");
	while (dir)
	{
		full_cmd = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_cmd)
		{
			free(path_cp);
			return (NULL);
		}
		sprintf(full_cmd, "%s/%s", dir, cmd);

		if (stat(full_cmd, &st) == 0)
		{
			free(path_cp);
			return (full_cmd);
		}

		free(full_cmd);
		dir = strtok(NULL, ":");
	}

	free(path_cp);
	return (NULL);
}
