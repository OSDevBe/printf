#include "main.h"

void handle_percent(const char *format, func_t f_list[], va_list ap, int *cnt);

/**
 * fchecker - check format for symbols
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
	int i = 0, counter = 0;

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case '%':
			handle_percent(format + i, f_list, ap, &counter);
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

/**
 * handle_percent - Handle '%' character in format
 *
 * @format: Format string
 * @f_list: List of functions
 * @ap: va_list for variable arguments
 * @cnt: Pointer to the cnt of printed characters
 */

void handle_percent(const char *format, func_t f_list[], va_list ap, int *cnt)
{
	int j, tmp, flag = false;

	for (j = 0; f_list[j].c && (format[1] == f_list[j].c[0]); j++)
	{
		tmp = f_list[j].f(ap);
		if (tmp != -1)
		{
			*cnt += tmp;
			flag = true;
		}
		else
			exit(-1);
	}
	if (!flag)
		switch (format[1])
		{
		case '%':
			_putchar('%');
			(*cnt)++;
			break;
		default:
			_putchar('%');
			_putchar(format[1]);
			*cnt += 2;
			break;
		}
}