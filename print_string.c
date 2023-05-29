#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_string - prints a string
 * @s: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list s)
{
	char *str = va_arg(s, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}
