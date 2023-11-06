#include "shell.h"
/**
 * is_builtin - builtin function
 * @cmd: commands
 * Return: 0
 */
int is_builtin(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - handle builtin commands
 * @cmd: command
 * @argv: argument array
 * @stat: status
 * @index: index
 * Return: 0
 */
void handle_builtin(char **cmd, char **argv, int *stat, int index)
{
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, argv, stat, index);
	else if (_strcmp(cmd[0], "env") == 0)
		print_env(cmd, stat);
}

/**
 * exit_shell - exits shell
 * @cmd: command
 * @stat: status
 * @argv: argument array
 * @index: index
 * Return: 0
 */
void exit_shell(char **cmd, char **argv, int *stat, int index)
{
	int exit_value = (*stat);
	char *idx, mssg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive(cmd[1]))
		{
			exit_value = _atoi(cmd[1]);
		}
		else
		{
			idx = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			freearray(cmd);
			(*stat) = 2;
			return;
		}
	}
	freearray(cmd);
	exit(exit_value);
}

/**
 * print_env - prints env
 * @cmd: command
 * @stat: status
 * Return: 0
 */
void print_env(char **cmd, int *stat)
{
	int m;

	for (m = 0; environ[m]; m++)
	{
		write(STDOUT_FILENO, environ[m], _strlen(environ[m]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(cmd);
	(*stat) = 0;
}
