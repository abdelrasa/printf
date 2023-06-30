#include "main.h"

/**
 * func_size - Get the size specifier for the argument
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 * Return: Size specifier
 */
int func_size(const char *format, int *index)
{
	int size = 0;
	int current_index = *index + 1;

	if (format[current_index] == 'l')
		size = S_LONG;
	else if (format[current_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = current_index - 1;
	else
		*index = current_index;

	return (size);
}
