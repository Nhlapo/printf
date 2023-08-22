#include "main.h"

/**
 * get_precision - this function calculates the precision to print
 * @format: formatted strings to print
 * @i: list of arguments to print
 * @list: arguments.
 *
 * Return: return precision
 */

int get_precision(const char *format, int *i, va_list list)
{
	int custom = *i + 1;
	int precision = -1;

	if (format[custom] != '.')
		return (precision);

	precision = 0;

	for (custom += 1; format[custom] != '\0'; custom++)
	{
		if (is_digit(format[custom]))
		{
			precision *= 10;
			precision += format[custom] - '0';
		}
		else if (format[custom] == '*')
		{
			custom++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = custom - 1;

	return (precision);
}

