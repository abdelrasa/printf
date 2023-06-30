#include "main.h"

/**
 * func_width - Get the width specifier for printing
 * @format: Formatted string
 * @index: Current index in the format string
 * @args: List of arguments
 * Return: Width specifier
 */
int func_width(const char *format, int *index, va_list args)
{
	int width = 0;
	int current_index;

	for (current_index = *index + 1;
			format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}
