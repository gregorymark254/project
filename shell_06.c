#include "shell.h"

/**
 * show - showing shell display
*/

void show(void)

{
	PRINTER("$ ");
}

/**
 * error_print - showing error on shell
 * @input: Input to node
 * @counter:conter to node
 * @argv: argument
 * Return: null or address
*/

void error_print(char *input, int counter, char **argv)

{
	char *pr;

	PRINTER(argv[0]);
	PRINTER(": ");
	pr = _itoa(counter);
	PRINTER(pr);
	free(pr);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

