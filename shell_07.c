#include "shell.h"

/**
 * print_nbr - Print Unsigned Int Putchar
 * @n: pointer to node
 * Return: null or address
*/

void print_nbr(unsigned int n)

{
	unsigned int c = n;

	if ((c / 10) > 0)
		print_nbr(c / 10);
		
	_putchar(c % 10 + '0');
}

/**
 * print_nbr_in - printing number in putchar
 * @n: Integer
 * Return: null or address
*/

void print_nbr_in(int n)

{
	unsigned int c = n;

	if (n < 0)
	{
		_putchar('-');
		c = -c;
	}
	if ((c / 10) > 0)
		print_number(c / 10);

	_putchar(c % 10 + '0');
}

