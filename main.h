#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * struct ffunc - defines a structure for char and functions
 *
 * @c: symbol
 *
 * @f: function
 */
struct ffunc
{
	char *c;
	int (*f)(va_list);
};
typedef struct ffunc func_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list list);
int print_string(va_list list);

#endif /* _MAIN_H_ */