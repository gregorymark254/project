#include "shell.h"

/**
 * _strcopy - copying string
 * @dest: destination
 * @src: Source
 * Return: null or address
*/

char *_strcopy(char *dest, char *src)

{
	int c;

	c = 0;
	while (src[c])
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}

/**
 * _str_concat - concatinating two strings
 * @dest: destination/1str
 * @src: source/2str
 * Return: null or address
*/

char *_str_concat(char *dest, char *src)

{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _str_chr - locating a string character
 * @s: string
 * @c: character
 * Return: null or address
*/

char *_str_chr(char *s, char c)

{

	do{
		if (*s == c)
		{
			break;
		}
	}		
	while (*s++);

	return (s);
}

/**
 * _str_cmp - comparing 2 strings
 * @st1: first string
 * @st2: second string
 * @n: amount of characters to be compared
 * Return: null or address
*/

int _str_cmp(const char *st1, const char *st2, size_t n)

{
	size_t c;

	if (st1 == NULL)
		return (-1);
	for (c = 0; c < n && st2[c]; c++)
	{
		if (st1[c] != st2[c])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * _str_up - Duplicate A String
 * @str: string
 * Return: null or address
*/

char *_str_up(char *str)

{
	size_t len, c;
	char *str2;

	len = strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (c = 0; c <= len; c++)
	{
		str2[c] = str[c];
	}

	return (str2);
}

