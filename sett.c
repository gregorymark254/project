#include "shell.h"
/**
 * sett - set env var
 * @text: name
 * Return: void
 */
void sett(char *text)
{
	char *buff[3];
	char *delim = " ";
	int x;

	buff[0] = strtok(text, delim);
	buff[1] = strtok(NULL, delim);
	buff[2] = strtok(NULL, delim);
	x = setenv(buff[1], buff[2], 1);
	if (x == -1)
	{
		perror(".hsh");
	}
}
/**
 * unsett - unset env var
 * @text : name
 * Return: void
 */
void unsett(char *text)
{
	char *buff[2];
	char *delim = " ";
	int x;

	buff[0] = strtok(text, delim);
	buff[1] = strtok(NULL, delim);
	x = unsetenv(buff[1]);
	if (x == -1)
	{
		perror(".hsh");
	}
}
