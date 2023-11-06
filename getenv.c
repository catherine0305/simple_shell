#include "shell.h"
/**
 * _getenv - get env
 * @variable: environ variable
 * Return: NULL
 */
char *_getenv(char *variable)
{
	int m;
	char *tmp, *k, *value, *env;

	for (m = 0; environ[m]; m++)
	{
		tmp = _strdup(environ[m]);
		k = strtok(tmp, "=");
		if (_strcmp(k, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
