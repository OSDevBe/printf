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
	int i = 0, j, tmp, flag = 0, counter = 0;
	va_list ap;
	func_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_start(ap, format);
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
					flag = 1;
				}
			}
			if (flag == 0)
			{
				switch (format[i + 1])
				{
				case '%':
					_putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(format[i + 1]);
					break;
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
