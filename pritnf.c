#include <stdio.h>
#include <stdarg.h>

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
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    fputs(s, stdout);
                    count += strlen(s);
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count++;
                    break;
                }
                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    print_binary(num);
                    count += sizeof(unsigned int) * 8;
                    break;
                }
                case '%':
                {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                {
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
                }
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

void print_binary(unsigned int num)
{
    if (num > 1)
        print_binary(num / 2);

    putchar('0' + num % 2);
}

