#include "main.h"

/**
 * func_precision - Get the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 * @args: List of arguments
 * Return: Precision
 */
int func_precision(const char *format, int *index, va_list args)
{
	int precision = -1;
	int current_index = *index + 1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (precision);
}
