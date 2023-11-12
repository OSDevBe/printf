#include "main.h"

/**
 * _printf - manual printf
 *
 * @format: arg array of char
 *
 * Return: nbr of printed char Success or -1 ERROR
 */

int _printf(const char *format, ...)
{
	int counter = 0;
	va_list ap;
	func_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_start(ap, format);
	counter = fchecker(format, f_list, ap);
	if (counter == -1)
		return (-1);
	va_end(ap);
	return (counter);
}
