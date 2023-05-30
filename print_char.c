#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - Writes the character c to stdout
 * @c: Character to print
 *
 * Return: 1
 */
int print_char(va_list c)
{
	unsigned char character;

	character = va_arg(c, int);
	_putchar(character);
	return (1);
}

/**
 * print_porcentage - Write %
 *
 * Return: 1.
 */
int print_porcentage(void)
{
	_putchar('%');
	return (1);
}
