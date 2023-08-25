#include "shell.h"

/**
 * _concat - concating two strings
 * @end: first string and have the final result.
 * @str: strings
 * Return: null or address
*/

char *_concat(char *end, char *str)
{
	char *last = end;
	char *tmp = str;

	if (*last != '\0')
		last++;

	if (*tmp != '\0')
	{
		*last++ = *tmp++;
	}
	*last = '\0';

	return (end);
}

