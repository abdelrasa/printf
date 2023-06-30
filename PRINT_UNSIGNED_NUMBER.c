#include "main.h"
/**
 * func_printf_unsgnd - Prints unsigned number
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Flag calculations
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int func_printf_unsgnd(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
