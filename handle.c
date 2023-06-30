#include "main.h"
/**
 * process_print - Handles printing
 * @format: Formatted string
 * @index: Current index in the format string
 * @args: List of arguments to be printed
 * @buffer: Buffer array
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed or -1 on error
 */
int process_print(const char *format, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, unknown = 0, printed = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; fmt_types[j].fmt != '\0'; j++)
	{
		if (format[*index] == fmt_types[j].fmt)
			return (fmt_types[j].fn(args, buffer, flags, width, precision, size));
	}

	if (fmt_types[j].fmt == '\0')
	{
		if (format[*index] == '\0')
			return (-1);

		unknown += write(1, "%%", 1);

		if (format[*index - 1] == ' ')
			unknown += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);

			if (format[*index] == ' ')
				--(*index);
			return (1);
		}

		unknown += write(1, &format[*index], 1);
		return (unknown);
	}
	return (printed);
}
