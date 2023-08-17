#include "shell.h"

/**
 * read_file - showing command from file
 * @filename: file name
 * @argv: agrument
 * Return: null or address
*/

void file_read(char *filename, char **argv)

{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * file_treat- check command to execute
 * @line: start line of file
 * @counter: counting error
 * @fp: describing file
 * @argv: argument
 * Return : null or address
*/

void file_treat(char *line, int counter, FILE *fp, char **argv)

{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

	if (_strncmp(cmd[0], "exit", 4) == 0)
	{
		exit_bul_for_file(cmd, line, fp);
	}
	else if (check_builtin(cmd) == 0)
	{
		st = handle_builtin(cmd, st);
		free(cmd);
	}
	else
	{
		st = check_cmd(cmd, line, counter, argv);
		free(cmd);
	}
}


/**
 * exit_file - Exiting shell
 * @line: line of a file
 * @cmd: Command
 * @fd: describing a file
 * Return : null or address
*/


void exit_file(char **cmd, char *line, FILE *fd)

{
	int s, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("wrong number");
		}
	}
	s = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(s);
}

