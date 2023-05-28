#include "main.h"

/**
 * get_size - Calculates the size specifier for the argument
 * @format: Format string in which to print the arguments
 * @position: Position in the format string
 *
 * Return: Size specifier for the argument
 */
int get_size(const char *format, int *position)
{
	int current_pos = *position + 1;
	int size = 0;

	if (format[current_pos] == 'l')
		size = SIZE_LONG;
	else if (format[current_pos] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*position = current_pos - 1;
	else
		*position = current_pos;

	return size;
}


/**
 * get_precision - Calculates the precision for printing
 * @format: Format string in which to print the arguments
 * @position: Position in the format string
 * @args: List of arguments
 *
 * Return: Precision value
 */
int get_precision(const char *format, int *position, va_list args)
{
	int current_pos = *position + 1;
	int precision = -1;

	if (format[current_pos] != '.')
		return precision;

	precision = 0;

	for (current_pos += 1; format[current_pos] != '\0'; current_pos++)
	{
		if (is_digit(format[current_pos]))
		{
			precision *= 10;
			precision += format[current_pos] - '0';
		}
		else if (format[current_pos] == '*')
		{
			current_pos++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*position = current_pos - 1;

	return precision;
}


/**
 * get_flags - Calculates active flags
 * @format: Format string in which to print the arguments
 * @position: Position in the format string
 *
 * Return: Flags indicating active formatting options
 */
int get_flags(const char *format, int *position)
{
	int j, curr_pos;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_pos = *position + 1; format[curr_pos] != '\0'; curr_pos++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr_pos] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CH[j] == '\0')
			break;
	}

	*position = curr_pos - 1;

	return flags;
}


/**
 * get_width - Calculates the width for printing
 * @format: Format string in which to print the arguments
 * @position: Position in the format string
 * @args: List of arguments
 *
 * Return: Width value
 */
int get_width(const char *format, int *position, va_list args)
{
	int curr_pos;
	int width = 0;

	for (curr_pos = *position + 1; format[curr_pos] != '\0'; curr_pos++)
	{
		if (is_digit(format[curr_pos]))
		{
			width *= 10;
			width += format[curr_pos] - '0';
		}
		else if (format[curr_pos] == '*')
		{
			curr_pos++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*position = curr_pos - 1;

	return width;
}

