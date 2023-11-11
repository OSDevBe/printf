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
	int i, j, tmp, counter = 0;
	va_list ap;

	func_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(ap, format);

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case '%':
			for (j = 0; f_list[j].c != NULL; j++)
			{
				if (format[i + 1] == f_list[j].c[0])
				{
					tmp = f_list[j].f(ap);
					if (tmp != -1)
						counter += tmp;
					else
						return (-1);
				}
			}
			i++;
			break;
		default:
			_putchar(format[i]);
			counter++;
			break;
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
