#include "shell.h"

/**
 * previous - checking previous history
 * @input: input
 * Return: - null or address
*/

int previous(char *input)

{
	char *filename = ".simple_shell_previous";
	ssize_t fd, z;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		z = write(fd, input, len);
		if (z < 0)
			return (-1);
	}
	return (1);
}

/**
 * around_env - checking environment
 * @env:  Environment variables.
 * Return: Void
*/

void around_env(char **env)
{
	int c;

	for (c = 0; env[c]; c++)
	{
		free(env[c]);
	}
}

