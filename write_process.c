#include "main.h"
/* WRT NMbR */
/**
 * proces_number - Writes a number
 * @is_negative: number is negative
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer array
 * @flags: Active flags for formatting
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int proces_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	char p = ' ', extra_char = 0;
	int length = BUFF_SIZE - index - 1;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';
	return (write_num(index, buffer, flags, width, precision,
		length, p, extra_char));
}

/**
 * proces_num - Write a number
 * @index: Index
 * @buffer: Buffer array
 * @flags: Flags specifying formatting options
 * @width: Width
 * @precision: Precision
 * @length: Length of the number
 * @padding_char: Padding character
 * @extra_char: Extra character
 * Return: Number of printed characters.
 */
int proces_num(int index, char buffer[],
	int flags, int width, int precision,
	int length, char padding_char, char extra_char)
{
	int i, int padding_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2
			&& buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padding_char = ' ';
	if (precision > 0 && precision < length)
		padding_char = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding_char;
		buffer[i] = '\0';
		if (flags & F_MINUS && padding_char == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')
		{
			if (extra_char)
				buffer[--padding_start] = extra_char;
			return (write(1, &buffer[padding_start], i - padding_start) +
				write(1, &buffer[index], length - (1 - padding_start)));
		}
	}
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], length));
}

/**
 * proces_unsigned - Writes an unsigned number
 * @is_negative: Flag indicating if the number is negative
 * @index: Index
 * @buffer: Buffer array
 * @flags: Flags specifying formatting options
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of written characters.
 */
int proces_unsigned(int is_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, int length = BUFF_SIZE - index - 1;
	char padding_char = ' ';

	UNUSED(size);
	UNUSED(is_negative);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padding_char = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding_char;

		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1,
						&buffer[0], i));
			}
		else
		{
			return (write(1, &buffer[0], i) + write(1,
						&buffer[index], length));
		}
	}
	return (write(1, &buffer[index], length));
}
/**
 * proces_pntr - pointer
 * @buffer: Array of characters
 * @index: Index
 * @length: Length
 * @width: Width
 * @flags: Flags
 * @padding_char: Character representing the padding
 * @extra_char: Character representing the extra char
 * @padding_start: Index at which padding should start
 */
int proces_pntr(char buffer[], int index, int length,
	int width, int flags, char padding_char,
	char extra_char, int padding_start)
{
	int j;

	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = padding_char;
		buffer[j] = '\0';
		if (flags & F_MINUS && padding_char == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) +
					write(1, &buffer[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padding_char == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[3], j - 3) +
					write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padding_char == '0')
		{
			if (extra_char)
				buffer[--padding_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding_start], j - padding_start) +
				write(1, &buffer[index], length -
					(1 - padding_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

/* WrT HANDLE */
/**
 * proces_char - Prints a character
 * @c: Character to be printed
 * @buffer: Buffer array
 * @flags: Active flags for formatting
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int proces_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0;
	char p = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
		p = '0';
	buffer[j++] = c;
	buffer[j] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = p;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
