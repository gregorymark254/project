#include "shell.h"

/**
 * main - Simple Shell 
 * @argc: the argument counter
 * @argv: the argument value
 * Return: null or address
*/

int main(__attribute__((unused)) int argc, char **argv)

{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		file_read(argv[1], argv);
	signal(SIGINT, handle_signal);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_build(cmd, input, argv, counter);
		}
		else if (check_built_in(cmd) == 0)
		{
			st = built_in(cmd, st);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_shell(cmd, input, counter, argv);

		}
		free_all(cmd, input);
	}
	return (statue);
}

/**
 * check_built_in - check builtin command
 * @cmd:command to be checked
 * Return: null or address
*/

int check_built_in(char **cmd)

{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * create_environment - creating environment variable
 * @envi: enviroment variable
 * Return: null or address
*/

void create_environment(char **envi)

{
	int i;

	for (i = 0; environment[i]; i++)
		envi[i] = _strdup(environment[i]);
	envi[i] = NULL;
}

