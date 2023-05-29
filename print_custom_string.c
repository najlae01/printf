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
    char *str = va_arg(s, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            _putchar('\\');
            _putchar('x');
            _putchar((*str / 16) < 10 ? (*str / 16) + '0' : (*str / 16) - 10 + 'A');
            _putchar((*str % 16) < 10 ? (*str % 16) + '0' : (*str % 16) - 10 + 'A');
            count += 4;
        }
        else
        {
            _putchar(*str);
            count++;
        }

        str++;
    }

    return count;
}
