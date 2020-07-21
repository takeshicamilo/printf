#include "holberton.h"
/**
 * p_bin - prints
 * @list: argument
 * Return: number of characters
 */
int p_bin(va_list list)
{
	unsigned int binarynum = 0;
	unsigned int i = 1, rem;
	unsigned int temp = 1;
	unsigned int decimalnum = va_arg(list, unsigned int);

	while (decimalnum != 0)
	{
		rem = decimalnum % 2;
		decimalnum = decimalnum / 2;
		binarynum = binarynum + rem * temp;
		temp = temp * 10;
	}
	temp = temp / 10;
	while (temp >= 1)
	{
		_putchar((binarynum / temp) + '0');
		binarynum = (binarynum % temp);
		temp = (temp / 10);
		i++;
	}
	return (i);
}
