#include "shell.h"

/**
 * disp_his - displaying history
 * @c: command
 * @s: last executed node
 * Return: null or address
*/

int disp_his(__attribute__((unused))char **c, __attribute__((unused))int s)

{
	char *file_name = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int c = 0;
	char *er;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		c++;
		er = _itoa(c);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

/**
 * _print - executing echo
 * @cmd: command
 * Return: null or address
*/

int _print(char **cmd)

{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environment) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

