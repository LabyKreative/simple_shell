#include "main.h"
/**
 * _printd - a function that prints any number.
 * Return: void
 * @n: number
 */
void _printd(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;
	if (n1 / 10)
		_printd(n1 / 10);
	_putchar(n1 % 10 + '0');
}
