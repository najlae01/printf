#include "main.h"
#include <stdint.h>
#include <stdio.h>

/**
 * print_pointer - prints a pointer address
 * @p: The pointer to print
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list p)
{
    void *ptr = va_arg(p, void *);
    uintptr_t address = (uintptr_t)ptr;
    int count = 0;

    _putchar('0');
    _putchar('x');
    count += 2;

    if (address == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        char hexDigits[] = "0123456789abcdef";

        char hexAddress[16];  // Assuming pointer size is not larger than 16 hex digits
        int i = 0;

        while (address != 0)
        {
            hexAddress[i++] = hexDigits[address % 16];
            address /= 16;
        }

        for (i = i - 1; i >= 0; i--)
        {
            _putchar(hexAddress[i]);
            count++;
        }
    }

    return count;
}

