#include "main.h"

/**
 * get_flags - functions to calculate flags
 * @format: formatted string
 * @i: parameter
 * Return: return flags
 */

int get_flags(const char *format, int *i)
{
	int c, custom;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (custom = *i + 1; format[custom] != '\0'; custom++)
	{
		for (c = 0; FLAGS_CHAR[c] != '\0'; c++)
			if (format[custom] == FLAGS_CHAR[c])
			{
				flags |= FLAGS_ARRAY[c];
				break;
			}

		if (FLAGS_CHAR[c] == 0)
			break;
	}

	*i = custom - 1;

	return (flags);
}

