#include "main.h"
/* PRNT BNRY */
/**
 * binary - Prints binary
 * @args_list: List of arguments
 * @buffer: Buffer array
 * @flags: Flag indicating
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed.
 */
int binary(va_list args_list, char buffer[],
	int flags, int width, int precision, int size)
{
	int char_count;
	unsigned int divisor;
	unsigned int i;
	unsigned int sum;
	unsigned int num;
	unsigned int binary_digits[32];

	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);

	divisor = 2147483648; /* 2^31 */
	num = va_arg(args_list, unsigned int);
	binary_digits[0] = num / divisor;
	for (i = 1; i < 32; i++)
	{
		divisor /= 2;
		binary_digits[i] = (num / divisor) % 2;
	}
	for (i = 0, sum = 0, char_count = 0; i < 32; i++)
	{
		sum += binary_digits[i];
		if (sum || i == 31)
		{
			char binary_char = '0' + binary_digits[i];

			write(1, &binary_char, 1);
			char_count++;
		}
	}
	return (char_count);
}

/* HEX NMBR LOWER UPPER */
/**
 * prinft_hxd - Prints a hexadecimal number in upper or lower
 * @types: List of arguments
 * @map_to: Array of values
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @flag_ch: Flag character
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int prinft_hxd(va_list types, char map_to[], char buffer[], int flags,
	char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int numero = va_arg(types, unsigned long int);
	unsigned long int nt_num = numero;

	UNUSED(width);

	numero = trnsfrm_sz_unsgnd(numero, size);

	if (numero == 0)
		buffer[j--] = '0';

	buffer[BF_SIZE - 1] = '\0';

	while (numero > 0)
	{
		buffer[j--] = map_to[numero % 16];
		numero /= 16;
	}

	if (flags & F_HASH && nt_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/*PRNT NSGND NMBER HEXADECIMAL*/
/**
 * printf_hexadecimal - Prints an unsigned hexadecimal number
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int printf_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
				width, precision, size));
}

/*NUMBER OCTAL */
/**
 * prinft_octal - Prints an unsigned octal number
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int prinft_octal(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	unsigned long int initial_number = number;
	unsigned long int number = va_arg(types, unsigned long int);
	int index = BUFF_SIZE - 2;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[index--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && initial_number != 0)
		buffer[index--] = '0';

	index++;
	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}

/* UPPER HEXADECIMAL */
/**
 * func_printf_hexad_upp - Prints an unsigned upper hexadecimal number
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int func_printf_hexad_upp(va_list types, char buffer[], int flags, int width,
		int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',
				width, precision, size));
}
