#include "main.h"

/**
 * print_integer - prints integer
 *
 * @ap: List of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_integer(va_list ap)
{
	int n, div, len;
	unsigned int num;

	n = va_arg(ap, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * print_uint - prints unsigned int
 *
 * @ap: List of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_uint(va_list ap)
{
	int n, div, len;
	unsigned int num;

	n = va_arg(ap, int);
	div = 1;
	len = 0;

	num = n;

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
