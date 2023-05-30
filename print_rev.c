#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
* print_rev - prints a string in reverse
* @r: string to print
*
* Return: number of chars printed
*/
int print_rev(va_list r)
{
	char *string;
	int i, j = 0;

	string = va_arg(r, char *);
	if (string == NULL)
		string = ")llun(";
	for (i = 0; string[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(string[i]);
		j++;
	}
	return (j);
}
