#include "shell.h"
/**
 * _getpath - handles path
 * @cmd: command
 * Return: NULL
 */
char *_getpath(char *cmd)
{
	char *path_env, *fullcmd, *dir;
	struct stat st;
	int m;

	for (m = 0; cmd[m]; m++)
	{
		if (cmd[m] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		fullcmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (fullcmd)
		{
			_strcpy(fullcmd, dir);
			_strcat(fullcmd, "/");
			_strcat(fullcmd, cmd);
			if (stat(fullcmd, &st) == 0)
			{
				free(path_env);
				return (fullcmd);
			}
			free(fullcmd), fullcmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
