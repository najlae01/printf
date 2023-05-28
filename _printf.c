#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * custom_printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int custom_printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				flush_buffer(buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			flush_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	flush_buffer(buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Character array (buffer)
 * @buffer_index: Index at which to add the next character, represents the length
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}

