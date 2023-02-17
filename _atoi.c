#include "main.h"
/**
 * _atoi - function that looks for numbers of a string and
 * convert them into integers.
 * @s: pointer to the string to be iterated.
 * Return: number and sign of an array, or 0 if no number.
 */
int _atoi(char *s)
{
	int array;
	int sign;
	int num;
	int out;

	num = 0;
	sign = 0;
	out = 0;
	for (array = 0; s[array] != '\0'; array++)
	{
		if (s[array] == '-')
		{
			sign++;
		}
		if (s[array] >= 48 && s[array] <= 57)
		{
			num = num * 10 - (s[array] - '0');
			out = 1;
		}
		else if (out == 1)
		{
			break;
		}
	}
	if ((sign - 1) % 2 != 0)
		num = num * -1;
	return (num);
}
