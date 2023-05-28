#include "main.h"

/**
 * check_printable - Checks if a character is printable
 * @c: The character to be evaluated.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */
int check_printable(char c)
{
    if (c >= 32 && c < 127)
        return 1;

    return 0;
}

/**
 * append_hex_code - Appends the ASCII code in hexadecimal format to a buffer
 * @buffer: The character buffer.
 * @index: The index at which to start appending.
 * @ascii_code: The ASCII code to be appended.
 *
 * Return: Always 3.
 */
int append_hex_code(char ascii_code, char buffer[], int index)
{
    char mapping[] = "0123456789ABCDEF";

    /* The hexadecimal code is always 2 digits long */
    if (ascii_code < 0)
        ascii_code *= -1;

    buffer[index++] = '\\';
    buffer[index++] = 'x';

    buffer[index++] = mapping[ascii_code / 16];
    buffer[index] = mapping[ascii_code % 16];

    return 3;
}

/**
 * is_digit_char - Verifies if a character is a digit
 * @c: The character to be evaluated.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit_char(char c)
{
    if (c >= '0' && c <= '9')
        return 1;

    return 0;
}

/**
 * convert_to_size - Casts a number to the specified size
 * @num: The number to be casted.
 * @size: The size indicating the type to be casted.
 *
 * Return: The casted value of num.
 */
long int convert_to_size(long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (short)num;

    return (int)num;
}

/**
 * convert_to_unsigned_size - Casts an unsigned number to the specified size
 * @num: The number to be casted.
 * @size: The size indicating the type to be casted.
 *
 * Return: The casted value of num.
 */
long int convert_to_unsigned_size(unsigned long int num, int size)
{
    if (size == S_LONG)
        return num;
    else if (size == S_SHORT)
        return (unsigned short)num;

    return (unsigned int)num;
}

