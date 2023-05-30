#include "main.h"
#include <stdio.h>
#include <stdint.h>

/**
 * print_custom_string - prints a custom string with non-printable characters
 * @s: The string to print
 *
 * Return: The number of characters printed
 */
int print_custom_string(va_list s)
{
	char *stri = va_arg(s, char *);
	int count = 0;

	if (stri == NULL)
		stri = "(null)";
	while (*stri)
	{
		if (*stri < 32 || *stri >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar((*stri / 16) < 10 ? (*stri / 16) + '0' : (*stri / 16) - 10 + 'A');
			_putchar((*stri % 16) < 10 ? (*stri % 16) + '0' : (*stri % 16) - 10 + 'A');
			count += 4;
		}
		else
		{
			_putchar(*stri);
			count++;
		}
		stri++;
	}
	return (count);
}
