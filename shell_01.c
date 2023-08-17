#include "shell.h"

/**
 * _putchar - insert the character
 * @c: publish character
 * Return: null 
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _string_copy - copying a string to a node
 * @destination: pointer to node
 * @src: node character
 * @n: int
 * Return: character
*/

char *_string_copy(char *destination, char *src, int n)

{
	int i = 0;

	while (i < n && *(src + i))
	{
		*(destination + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(destination + i) = '\0';
		i++;
	}
	return (destination);
}

/**
 * _string_length - showing length
 * @s: character
 * Return: int
*/

int _string_length(char *s)

{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _convert - changing to integer
 * @s:string
 * Return:int
*/

int _convert(char *s)

{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}

/**
 * _put_str - to print a string
 * @str:pointer char
 * return:void
*/

void _put_str(char *str)

{
	int c;

	for (c = 0; str[c] != '\0'; c++)
	{
		_putchar(str[c]);
	}
	_putchar('\n');
	return;
}

