#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            // Check the conversion specifier
            switch (*format)
            {
                case 'c':
                {
                    int c = va_arg(args, int);
                    count += _putchar(c);
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    int len = 0;
                    while (s[len])
                        len++;
                    count += write(1, s, len);
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                case '%':
                {
                    count += _putchar('%');
                    break;
                }
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += print_binary(num);
                    break;
                }
                default:
                {
                    count += _putchar('%');
                    count += _putchar(*format);
                    break;
                }
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return count;
}

int print_binary(unsigned int num)
{
    if (num > 1)
        return print_binary(num / 2) + _putchar('0' + num % 2);
    else
        return _putchar('0' + num);
}

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return 0;
}

