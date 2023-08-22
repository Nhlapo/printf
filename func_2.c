#include "main.h"


/**
 * print_pointer - this function prints value of pointer variable
 * @types: arguments
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width
 * @precision: precision
 * @size: Size
 * Return: return number of characters printed
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra = 0, pad = ' ';
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_address;
	char map[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)addrs;

	while (num_address > 0)
	{
		buffer[index--] = map[num_address % 16];
		num_address /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		extra = '+', len++;
	else if (flags & F_SPACE)
		extra = ' ', len++;

	index++;

	return (write_pointer(buffer, index, len,
		width, flags, pad, extra, pad_start));
}

/**
 * print_non_printable - this function prints ascii codes in hexa
 *			 of non printable chars
 * @types: arguments
 * @buffer: buffer array that handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: return number of characters printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, start = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j]))
			buffer[j + start] = str[j];
		else
			start += append_hexa_code(str[j], buffer, j + start);

		j++;
	}

	buffer[j + start] = '\0';

	return (write(1, buffer, j + start));
}


/**
 * print_reverse - this function prints string in reverse
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: return numbers of character printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string;
	int i, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(types, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}

/**
 * print_rot13string - this function print a string in rot13.
 * @types: arguments
 * @buffer: buffer array to handle print
 * @flags: active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: numbers of characters printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *string;
	unsigned int i, j;
	int counter = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == string[i])
			{
				x = output[j];
				write(1, &x, 1);
				counter++;
				break;
			}
		}
		if (!input[j])
		{
			x = string[i];
			write(1, &x, 1);
			counter++;
		}
	}
	return (counter);
}

