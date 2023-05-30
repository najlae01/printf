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
	char *string = va_arg(s, char *);
	int count = 0;

	if (string == NULL)
		string = "(null)";

	while (*string)
	{
		_putchar(*string);
		string++;
		count++;
	}

	return (count);
}
