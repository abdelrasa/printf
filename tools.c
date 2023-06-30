#include "main.h"

/**
 * func_printable - character printable
 * @c: Character
 * Return: one if c is printable, zero otherwise
 */
int func_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * func_appndhexa - Appends ASCII in hexadecimal
 * @buffer: Array of characters
 * @index: Index
 * @ascii_code: ASCII code
 * Return: Always 3
 */
int func_appndhexa(char ascii_code, char buffer[], int index)
{
	char hex_map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = hex_map[ascii_code / 16];
	buffer[index] = hex_map[ascii_code % 16];

	return (3);
}

/**
 * func_dg - Verifies the character
 * @c: Character
 * Return: 1 if c is a digit, 0 otherwise
 */
int func_dg(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * trnsfrm_sz_nmbr - Casts a number size
 * @num: Number
 * @size: Size
 * Return: Casted value of num
 */
long int trnsfrm_sz_nmbr(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * trnsfrm_sz_unsgnd - Casts an unsigned number
 * @num: Number
 * @size: Size
 * Return: Casted value of num
 */
unsigned long int trnsfrm_sz_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
