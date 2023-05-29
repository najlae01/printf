#include "main.h"
#include <stdio.h>
#include <stdint.h>

int printf_hex(unsigned long value);

/**
 * print_pointer - prints the value of a pointer
 * @p: The pointer to print
 *
 * Return: The number of characters printed.
 */

int print_pointer(va_list p)
{
	uintptr_t pointer = (uintptr_t)va_arg(p, void *);

	_putchar('0');
	_putchar('x');
	return (printf_hex((unsigned long)pointer) + 2);
}

/**
 * printf_hex - prints a hexadecimal value
 * @value: The value to print
 *
 * Return: The number of characters printed.
 */
int printf_hex(unsigned long value)
{
	int count = 0;
	char hex[16];
	int i;
	int digit;

	if (value == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (value != 0)
		{
			digit = value % 16;
			if (digit < 10)
				hex[count] = digit + '0';
			else
				hex[count] = digit - 10 + 'A';
			value /= 16;
			count++;
		}
		for (i = count - 1; i >= 0; i--)
			_putchar(hex[i]);
	}
	return (count);
}

