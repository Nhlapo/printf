#include "main.h"


/**
 * get_size - this function calculates the size of argument
 * @format: formatted string
 * @i: list of arguments to print
 *
 * Return: return precision
 */


int get_size(const char *format, int *i)
{
	int custom = *i + 1;
	int size_i = 0;

	if (format[custom] == 'l')
		size_i = S_LONG;
	else if (format[custom] == 'h')
		size_i = S_SHORT;

	if (size_i == 0)
		*i = custom - 1;
	else
		*i = custom;

	return (size_i);
}

