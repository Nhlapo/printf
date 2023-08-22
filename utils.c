#include "main.h"

/**
 * is_printable - this function checks if a char can be printed
 * @c: char to check
 *
 * Return: return 1 if c can be printed, else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ASCII in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index to start appending
 * @ascii_code: ASCII code
 * Return: return 3 always
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a character is a digit
 * @c: character to check
 *
 * Return: return i if char is digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Change a number to the specified size
 * @num: number to change
 * @size: number indicating type to change
 *
 * Return: return value of num
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - change a num to the specified size
 * @num: number to change
 * @size: number indicating the type to change
 *
 * Return: return changed value of num
 */

long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

