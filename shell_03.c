#include "shell.h"

/**
 * built_in - handling build in command
 * @cmd: Command
 * @er: last executed node
 * Return: null or address
*/

int built_in(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", change},
		{"env", display},
		{"help", show_help},
		{"echo", echo},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}

/**
 * check_cmd - execute shell comand
 * @cmd: Command
 * @input: input
 * @c: executing shell
 * @argv: argument
 * Return: null or address
*/

int check_shell(char **cmd, char *input, int c, char **argv)

{
	int s;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environment) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&s);
	return (0);
}

/**
 * handle_sign - handling control c
 * @sig: showing the signal
 * Return: null or address
*/

void handle_signal(int sign)

{
	if (sign == SIGINT)
	{
		PRINTER("\n$ ");
	}
}

