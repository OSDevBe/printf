#include "main.h"

/**
 * fchekcer - check format for symbols
 *
 * @format: arg string
 *
 * @f_list: struct of symbols + functions
 *
 * @ap: args of _printf
 *
 * Return: nbr of printed chars
*/
int fchecker(const char *format, func_t f_list[], va_list ap)
{
	int i = 0, j, tmp, flag = 0, counter = 0;

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
					counter++;
					break;
				default:
					_putchar('%');
					_putchar(format[i + 1]);
					counter = counter + 2;
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
	return (counter);
}
