#include "shell.h"

/**
 * path_cmd -  path to be executed
 * @cmd: command
 * Return: null or address
*/

int path_shell(char **cmd)

{
	char *path, *value, *path_shell;
	struct stat buf;

	path = get_env("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		path_shell = shell_build(*cmd, value);
		if (stat(path_shell, &buf) == 0)
		{
			*cmd = _strdup(path_shell);
			free(path_shell);
			free(path);
			return (0);
		}
		free(path_shell);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * shell_build - Build Command
 * @token: command to to executed
 * @value: folder where command is foung
 * Return: null or address
*/

char *shell_build(char *token, char *value)

{
	char *cmd;
	size_t len;

	len = strlen(value) + strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * get_env - getting the environment variables
 * @name: the environment name
 * Return: null or address
*/

char *get_env(char *name)

{
	size_t en, ne;
	char *value;
	int i, x, j;

	en = strlen(name);
	for (i = 0 ; environment[i]; i++)
	{
		if (_strncmp(name, environment[i], en) == 0)
		{
			ne = strlen(environment[i]) - en;
			value = malloc(sizeof(char) * ne);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = en + 1; environment[i][x]; x++, j++)
			{
				value[j] = environment[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}

