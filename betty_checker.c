#include "shell.h"

/**
 * checker - see if it matches any character
 * @i: character to be checked
 * @str: string to be checked
 * Return: null or address
*/

unsigned int checker(char c, const char *str)

{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - tocken of node
 * @str: string of node
 * @delim: delim to node
 * Return: null or address
*/

char *_strtok(char *str, const char *delim)

{
	static char *ac;
	static char *vn;
	unsigned int i;

	if (str != NULL)
		vn = str;
	ac = vn;
	if (ac == NULL)
		return (NULL);
	for (i = 0; ac[i] != '\0'; i++)
	{
		if (checker(ac[i], delim) == 0)
			break;
	}
	if (vn[i] == '\0' || vn[i] == '#')
	{
		vn = NULL;
		return (NULL);
	}
	ac = vn + i;
	vn = ac;
	for (i = 0; vn[i] != '\0'; i++)
	{
		if (checker(vn[i], delim) == 1)
			break;
	}
	if (vn[i] == '\0')
		vn = NULL;
	else
	{
		vn[i] = '\0';
		vn = vn + i + 1;
		if (*vn == '\0')
			vn = NULL;
	}
	return (ac);
}

