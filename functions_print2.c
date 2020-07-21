#include "holberton.h"
/**
 * p_bin - prints
 * @list: argument
 * Return: number of characters
 */
int p_bin(va_list list)
{
	long binarynum = 0;
	int i, rem, temp = 1;
	int decimalnum = va_arg(list, int);

	while (decimalnum != 0)
	{
		rem = decimalnum % 2;
		decimalnum = decimalnum / 2;
		binarynum = binarynum + rem*temp;
		temp = temp * 10;
	}
	i = print_number(binarynum);
	return (i);
}

/**
 * print_number - function that prints an integer..
 * @n: number of times that the diagonal will be printed.
 *
 * Return: void.
 *
 */
int print_number(int n)
{
	int cont;
	int aux, i = 1;

	if (n < 0)
	{
		_putchar('-');
		aux = n;
		cont = -1;
		while (aux < -9)
		{
			aux = (aux / 10);
			cont = (cont * 10);
		}
		while (cont <= -1)
		{
			_putchar((n / cont) + '0');
			n = (n % cont);
			cont = (cont / 10);
			i++;
		}
	}
	else
	{
		aux = n;
		cont = 1;
		while (aux > 9)
		{
			aux = (aux / 10);
			cont = (cont * 10);
		}
		while (cont >= 1)
		{
			_putchar((n / cont) + '0');
			n = (n % cont);
			cont = (cont / 10);
			i++;
		}
	}
	return (i);
}
