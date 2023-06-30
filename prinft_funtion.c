#include "main.h"
/**
 * funct_char - Prints a char
 * @args_list: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Flag indicating active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int funct_char(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	char character = va_arg(args_list, int);

	return (handle_write_char(character, buffer,
				flags, width, precision, size));
}

/**
 * funct_int - Prints an integer
 * @args_list: List of arguments
 * @buffer: Buffer
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number char
 */
int funct_int(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	int ngtv = 0;
	long int nmb = va_arg(args_list, long int);
	int j = BUFF_SIZE - 2;
	unsigned long int v;

	nmb = convert_size_number(nmb, size);

	if (nmb == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	v = (unsigned long int)nmb;

	if (nmb < 0)
	{
		v = (unsigned long int)((-1) * nmb);
		ngtv = 1;
	}

	while (v > 0)
	{
		buffer[j--] = (v % 10) + '0';
		v /= 10;
	}

	j++;

	return (write_number(ngtv, j, buffer, flags, width, precision, size));
}

/* PERCENT SIGN */
/**
 * funct_percent - Prints a percent sign
 * @args_list: List of arguments
 * @buffer: Buffer array
 * @flags: Flag indicating
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of characters printed
 */
int funct_percent(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(size);
	UNUSED(width);
	UNUSED(args_list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);

	return (write(1, "%%", 1));
}
/**
 * funct_string - Prints a string
 * @args_list: List of arguments
 * @buffer: Buffer array
 * @flags: Flag indicating
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int funct_string(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	int padding_length;
	int str_length = 0;
	char *str = va_arg(args_list, char *);

	UNUSED(flags);
	UNUSED(size);
	UNUSED(buffer);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[str_length] != '\0')
		str_length++;
	if (precision >= 0 && precision < str_length)
		str_length = precision;
	if (width > str_length)
	{
		padding_length = width - str_length;
		if (flags & F_MINUS)
		{
			write(1, str, str_length);
			while (padding_length > 0)
			{
				write(1, " ", 1);
				padding_length--;
			}
			return (width);
		}
		else
		{
			while (padding_length > 0)
			{
				write(1, " ", 1);
				padding_length--;
			}
			write(1, str, str_length);
			return (width);
		}
	}
	return (write(1, str, str_length));
}
