#include "shell.h"

/**
 * _compare - comparing two strings
 * @str1: first string
 * @str2: second string
 * Return: null or address
*/

int _compare(char *str1, char *str2)

{
	int cmp = 0, c, len1, len2;
	len1 = strlen(str1);
	len2 = strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (c = 0; str1[c]; c++)
	{
		if (str1[c] != str2[c])
		{
			cmp = str1[c] - str2[c];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _alpha - check if is alphabetic
 *@c: character
 * Return: null or address
*/

int _alpha(int c)

{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _conv_int - converting an integer
 * @i: interger
 * Return: null or address
*/

char *_conv_int(unsigned int i)

{
	int len = 0, c = 0;
	char *s;

	len = int_length(i);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (i / 10)
	{
		s[c] = (i % 10) + '0';
		i /= 10;
		c++;
	}
	s[c] = (i % 10) + '0';
	rev_array(s, len);
	s[c + 1] = '\0';
	return (s);
}

/**
 *  rev_array - reversing an aray
 * @arr: array
 * @len: length
 * Return: null or address
*/

void rev_array(char *arr, int len)

{
	int c;
	char tmp;

	for (c = 0; c < (len / 2); c++)
	{
		tmp = arr[c];
		arr[c] = arr[(len - 1) - c];
		arr[(len - 1) - c] = tmp;
	}
}

/**
 * int_length - showing length of integer
 * @i: integer
 * Return: null or address
*/

int int_length(int i)

{
	int len = 0;

	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

