#include "shell.h"
/**
 * exec - exec function
 * @cmd: command
 * @argv: argument array
 * @index: index
 * Return: exit status
 */
int exec(char **cmd, char  **argv, int index)
{
	pid_t child;
	int stat;
	char *fullcmd;

	fullcmd = _getpath(cmd[0]);
	if (!fullcmd)
	{
		printerror(argv[0], cmd[0], index);
		freearray(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(fullcmd, cmd, environ) == -1)
		{
			free(fullcmd), fullcmd = NULL;
			freearray(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray(cmd);
		free(fullcmd), fullcmd = NULL;
	}
	return (WEXITSTATUS(stat));
}
