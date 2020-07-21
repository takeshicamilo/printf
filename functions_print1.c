#include "holberton.h"
/**
 * p_dec - prints
 * @list: argument
 * Return: number of characters
 */
int p_dec(va_list list)
{
	int n = va_arg(list, int), num, last = n % 10, dig, exp = 1, i = 1;

	n = n / 10;
	num = n;

	while (num / 10 != 0)
	{
		exp = exp * 10;
		num = num / 10;
	}
	num = n;

	if (num < 0)
	{
		_putchar('-');
		while (exp != 0)
		{
			dig = num / (-exp);
			_putchar(dig + '0');
			num = num % exp;
			exp = exp / 10;
			i++;
		}
		_putchar(-last + '0');
	}
	if (num > 0)
	{
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num % exp;
			exp = exp / 10;
			i++;
		}
		_putchar(last + '0');
	}

	return (i);
}
/**
 * p_int - prints integer
 * @list: argument
 * Return: number of characters printed
 */
int p_int(va_list list)
{

	int n = va_arg(list, int);
	int num;
	int last = n % 10;
	int dig;
	int exp = 1;
	int i = 1;

	n = n / 10;
	num = n;
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');
	return (i);
}
