#include "simple_shell.h"

/**
 * free_tokens - Frees array of strings.
 * @tokens: The token array.
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;

	while (tokens[i])
		free(tokens[i++]);

	free(tokens);
}
