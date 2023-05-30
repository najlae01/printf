#include "main.h"

/**
 * print_int - function that prints an integer
 * @i: integer to print
 *
 * Description: prints digits with _putchar
 * Return: size of the output text
 */
int print_int(va_list i)
{
    int n = va_arg(i, int);
    int count = 0;
    bool flag_plus = false;
    bool flag_space = false;
    bool flag_hash = false;

    handle_flags(&count, flag_plus, flag_space, flag_hash);

    int len, powten, j, digit, num;

    if (n != 0)
    {
        if (n < 0)
        {
            _putchar('-');
            count++;
            n *= -1;
        }
        num = n;
        len = 0;
        while (num != 0)
        {
            num /= 10;
            len++;
        }
        powten = 1;
        for (j = 1; j <= len - 1; j++)
            powten *= 10;
        for (j = 1; j <= len; j++)
        {
            digit = n / powten;
            _putchar(digit + '0');
            count++;
            n -= digit * powten;
            powten /= 10;
        }
    }
    else
    {
        _putchar('0');
        return 1;
    }
    return count;
}
