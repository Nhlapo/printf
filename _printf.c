#include "main.h"

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);
    
	int count = 0;

	while (*format != '\0') {
		if (*format == '%') {
			format++; // Move past '%'

			if (*format == '\0') {
				break; // If format ends with '%', stop
			}

			if (*format == 'c') {
				int ch = va_arg(args, int);
				putchar(ch);
				count++;
			} else if (*format == 's') {
				char *str = va_arg(args, char *);
					while (*str != '\0') {
					putchar(*str);
					str++;
					count++;
				}
			} else if (*format == '%') {
				putchar('%');
				count++;
			} else {
			// Invalid format specifier, ignore
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

int main() {
	_printf("Hello, %s! This is a %c and a percent %% sign.\n", "world", 'c');
	return 0;
}
