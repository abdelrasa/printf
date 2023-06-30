#include "main.h"

/**
 * bff_print - Prints the contents of buffer
 * @buffer: rray of characters
 * @buff_ind: Index
 */
void bff_print(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format
 * Return: number of chars
 */
int _printf(const char *format, ...)
{
	int i, p = 0, crctrs = 0;
	int fg, width, pr, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				bff_print(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			crctrs++;
		}
		else
		{
			bff_print(buffer, &buff_ind);
			fg = get_flags(format, &i);
			width = get_width(format, &i, list);
			pr = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
				fg, width, pr, size);
			if (p == -1)
				return (-1);
			crctrs += p;
		}
	}

	bff_print(buffer, &buff_ind);
	va_end(list);
	return (crctrs);
}
