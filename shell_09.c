#include "shell.h"

/**
 *  _error - show error
 * @argv: argument
 * @c: conting errors
 * @cmd:  command
 * Return: null or address
*/

void _error(char **argv, int c, char **cmd)

{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": invalid number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}

