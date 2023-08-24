#include "shell.h"

/**
 * main - starting point of the program
 * @argc: argument to counter
 * @argv: argument to values
 * @env: environment variable
 * Return: null or address
*/

int main(int argc, char **argv, char **env)

{
	int i;

	i = begin(argc, argv, env);

	return (i);
}
