#include "main.h"

int _printf(const char *format, ...) {

	int count = 0;
	char ch;
	char *str;
	unsigned int ui;
	void *addr;

	va_list args;
	va_start(args, format);

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
			} else if (*format == 'd' || *format == 'i') {
				int num = va_arg(args, int);
				printf("%d", num);
				count++;
			} else if (*format == 'u') {
				ui = va_arg(args, unsigned int);
				printf("%u", ui);
				count++;
			} else if (*format == 'o') {
				ui = va_arg(args, unsigned int);
				printf("%o", ui);
				count++;
			} else if (*format == 'x' || *format == 'X') {
				ui = va_arg(args, unsigned int);
				printf("%x", ui);
				count++;
			} else if (*format == 'p') {
				addr = va_arg(args, void *);
				printf("%p", addr);
				count++;
			} else if (*format == '%') {
				putchar('%');
				count++;
			} else {

				printf("Unknown:[%%%c]", *format);
				count += 12;
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
