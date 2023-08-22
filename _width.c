#include "main.h"

/**
 * get_width - this function calculates the width to be printed
 * @format: formatted string
 * @i: arguments to be printed
 * @list: list of argument
 *
 * Return: return width
 */

int get_width(const char *format, int *i, va_list list)
{
	int custom;
	int width = 0;

	for (custom = *i + 1; format[custom] != '\0'; custom++)
	{
		if (is_digit(format[custom]))
		{
			width *= 10;
			width += format[custom] - '0';
		}
		else if (format[custom] == '*')
		{
			custom++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = custom - 1;

	return (width);
}

