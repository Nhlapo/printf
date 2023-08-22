#include "main.h"

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int count = 0;
	char ch;
	char *str;

	while (*format != '\0') {
		if (*format == '%') {
			format++;

			if (*format == 'c') {
				ch = (char)va_arg(args, int);
				putchar(ch);
				count++;
			} else if (*format == 's') {
				str = va_arg(args, char *);
				while (*str != '\0') {
					putchar(*str);
					str++;
					count++;
				}
			} else if (*format == '%') {
				putchar('%');
				count++;
			}
		} else {
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return count;
}
