#include "shell.h"
/**
 * token - tokenizes strings
 * @line: string
 * Return: tokenized string
 */
char **token(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **cmd = NULL;
	int z = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);

	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		z++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (z + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}

	token = strtok(line, DELIM);
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
