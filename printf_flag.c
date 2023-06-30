#include "main.h"

/**
 * func_flags - Get active flags based on format string
 * @format: Formatted string
 * @index: Current index in the format string
 * Return: Active flags
 */
int func_flags(const char *format, int *index)
{
	/* Flag characters: - + 0 # ' ' */
	/* Flag values:     1  2 4  8  16 */
	int flags = 0;
	int j, current_index;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *index + 1;
			format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAG_CHARACTERS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAG_CHARACTERS[j])
			{
				flags |= FLAG_VALUES[j];
				break;
			}
		}

		if (FLAG_CHARACTERS[j] == 0)
			break;
	}

	*index = current_index - 1;

	return (flags);
}
