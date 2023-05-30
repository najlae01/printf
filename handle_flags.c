#include <stdbool.h>

/**
 * handle_flags - handles the flag characters
 * @count: pointer to the count variable
 * @flag_plus: flag for '+'
 * @flag_space: flag for ' '
 * @flag_hash: flag for '#'
 */
void handle_flags(int *count, bool flag_plus, bool flag_space, bool flag_hash)
{
    if (flag_plus)
    {
        _putchar('+');
        (*count)++;
    }
    else if (flag_space)
    {
        _putchar(' ');
        (*count)++;
    }

    if (flag_hash)
    {
        _putchar('0');
        _putchar('x');
        (*count) += 2;
    }
}
