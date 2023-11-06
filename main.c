#include "shell.h"
/**
 * main - main function
 * @ac: argument count
 * @argv: argument array
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **cmd = NULL;
	int stat = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = read_line();
		if (line == NULL) /**EOF ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		index++;
		cmd = token(line);
		if (!cmd)
			continue;
		if (is_builtin(cmd[0]))
			handle_builtin(cmd, argv, &stat, index);

		stat = exec(cmd, argv, index);
	}
}
