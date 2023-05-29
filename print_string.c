#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 *
 * Return: The number of characters printed.
 */
int print_string(va_list s)
{
	char *my_string;
	int i, count = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";

	for (i = 0; my_string[i] != '\0'; i++)
	{
		if (my_string[i] < ' ' || my_string[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (my_string[i] < 16)
				_putchar('0');
			count += 3;
			count += print_hex(my_string[i]);
		}
		else
		{
			_putchar(my_string[i]);
			count++;
		}
	}

	return count;
}

/**
 * print_hex - prints a hexadecimal value of a given character.
 * @value: The character value.
 *
 * Return: The number of characters printed.
 */
int print_hex(char value)
{
	int count = 0;
	char hex[2];

	hex[0] = "0123456789ABCDEF"[(value >> 4) & 0x0F];
	hex[1] = "0123456789ABCDEF"[value & 0x0F];

	_putchar(hex[0]);
	_putchar(hex[1]);
	count += 2;

	return count;
}

