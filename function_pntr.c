#include "main.h"
/* STRNG RT13 */
/**
 * func_printf_rot13_string - Prints a string in ROT13.
 * @args: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Flag calculations
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int func_printf_rot13_string(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int i, j;
	char *str;
	char x;
	int count = 0;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(precision);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);

	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; alphabet[j]; j++)
		{
			if (alphabet[j] == str[i])
			{
				x = rot13[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!alphabet[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}

/* NON-PRNTBL CHRCTRS */
/**
 * func_non_prntbl - Prints ASCII codes in hexadecimal
 * @args: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int func_non_prntbl(va_list args, char buffer[], int flags, int width,
		int precision, int size)
{
	char *str = va_arg(args, char *);
	int index = 0, offset = 0;

	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[index] != '\0')
	{
		if (is_printable(str[index]))
			buffer[index + offset] = str[index];
		else
			offset += append_hexa_code(str[index], buffer, index + offset);
		index++;
	}
	buffer[index + offset] = '\0';

	return (write(1, buffer, index + offset));
}

/* PNTR VLU */
/**
 * func_pointer - Prints value of a pointer
 * @args: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int func_pointer(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	int index = BUFF_SIZE - 2, length = 2, padding_start = 1;
	char extra_char = 0, padding = ' ';
	void *address = va_arg(args, void *);
	char mapping[] = "0123456789abcdef";
	unsigned long num_addresses;

	UNUSED(size);
	UNUSED(width);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addresses = (unsigned long)address;

	while (num_addresses > 0)
	{
		buffer[index--] = mapping[num_addresses % 16];
		num_addresses /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	index++;

	return (write_pointer(buffer, index, length, width, flags,
				padding, extra_char, padding_start));
}

/* PRNT RVRS STRNG */
/**
 * funt_reverse - Prints a string in reverse.
 * @args: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int funt_reverse(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{

	int index, count = 0;
	char *str;

	UNUSED(width);
	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	for (index = 0; str[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char character = str[index];

		write(1, &character, 1);
		count++;
	}

	return (count);
}
