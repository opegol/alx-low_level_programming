#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_char(va_list a);
void print_int(va_list a);
void print_float(va_list a);
void print_string(va_list a);
void print_all(const char * const format, ...);

/**
 * print_char - prints a char.
 * @a : pointer to variadic argument
 */
void print_char(va_list a)
{
	char c;

	c = va_arg(a, int);
	printf("%c", c);
}

/**
 * print_int - prints an int
 * @a : pointer to variadic argument
 */
void print_int(va_list a)
{
	int i;

	i = va_arg(a, int);
	printf("%d", i);
}

/**
 * print_float - prints a float
 * @a : pointer to variadic argument
 */
void print_float(va_list a)
{
	float f;

	f = va_arg(a, double);
	printf("%f", f);
}

/**
 * print_string - prints a string
 * @a : pointer to variadic argument
 */
void print_string(va_list a)
{
	char *s;

	s = va_arg(a, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format : is a list of types of arguments passed to the function
 * @... : variadic arguments
 */
void print_all(const char * const format, ...)
{
	va_list a;
	int i = 0, j = 0;
	char *sep = "";
	printer_t types[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};

	va_start(a, format);

	while (format != NULL && (*(format + i)))
	{
		j = 0;

		while (j < 4 && (*(format + i) != *(types[j].symbol)))
			j++;

		if (j < 4)
		{
			printf("%s", sep);
			types[j].print(a);
			sep = ", ";
		}

		i++;
	}

	printf("\n");

	va_end(a);
}

