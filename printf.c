#include "holberton.h"
/**
 * _printf - print
 * @format: char
 * Return: characters
 */
int _printf(const char *format, ...)
{
	va_list list;
	unsigned int i = 0, j = 0, check = 0, length = 0, l;

	print_t print[] = {{"c", p_char}, {"s", p_str}, {"d", p_dec},
		{"i", p_int}, {"b", p_bin}, {NULL, NULL}};
	va_start(list, format);
	while (format != NULL && format[i] != '\0')
	{
		l = 1;
		if (format[i] == '%' && format[i + 1] != '%')
		{
			for (j = 0; print[j].f != NULL; j++)
			{
				if (format[i + 1] == print[j].print[0])
				{
					l = print[j].f(list);
					check = 1;
					i++;
				}
			}
			if (check == 0)
			{
				_putchar(format[i]);
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		else
		{
			_putchar(format[i]);
		}
		length += l;
		i++;
	}
	va_end(list);
	return (length);
}
