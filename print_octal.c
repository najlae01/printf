#include "main.h"

/**
* print_octal - unsigned int argument is converted to unsigned octal
* @o: unsigned to be converted
* Descriptions: prints unsigned octal
* Return: size the output
*/
int print_octal(va_list o)
{
	unsigned int len, powten, i, digit, n, num;
	int count = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 8;
			len++;
		}
		powten = 1;
		for (i = 1; i <= len - 1; i++)
			powten *= 8;
		for (i = 1; i <= len; i++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
