#include "shell.h"

/**
 * exit_build - exiting Shell
 * @cmd: Command
 * @input: Inputing user
 * @argv: argument
 * @c: Excuting
 * Return: Void
*/

void  exit_build(char **cmd, char *input, char **argv, int d)

{
	int s, c = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][c])
	{
		if (_isalpha(cmd[1][c++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			s = atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(s);
		}
	}
}


/**
 * change - Change Dirctory
 * @cmd: Command
 * @er: Last Command 
 * Return: null or address
*/

int change(char **cmd, __attribute__((unused))int er)

{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * display - show enviroment
 * @cmd: Command
 * @er: Last command 
 * Return: null or address
*/


int display(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)

{
	size_t c;

	int len;

	for (c = 0; environment[c] != NULL; c++)
	{
		len = strlen(environment[c]);
		write(1, environment[c], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
 * show_help - showng help function
 * @cmd: Command
 * @er: Last command
 * Return: null or address
*/

int show_help(char **cmd, __attribute__((unused))int er)

{
	int fd, fw, rd = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * echo - Echo cases
 * @st:Last command 
 * @cmd:  Command
 * Return: null or address
*/

int echo(char **cmd, int st)

{
	char *track;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		track = _getenv("PATH");
		PRINTER(track);
		PRINTER("\n");
		free(track);

	}
	else
		return (print_echo(cmd));

	return (1);
}

