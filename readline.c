#include "shell.h"
/**
 * read_line - read line function
 * Return: line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t ln = 0;
	ssize_t m;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	m = getline(&line, &ln, stdin);
	if (m == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
