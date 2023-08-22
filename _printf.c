#include "main.h"

void printChar(char ch, int *count) {
	putchar(ch);
	(*count)++;
}

void printString(const char *str, int *count) {
	while (*str != '\0') {
		putchar(*str);
		str++;
		(*count)++;
	}
}

void printInteger(int num, int *count) {
	printf("%d", num);
	(*count)++;
}

void printUnsignedInt(unsigned int ui, int *count) {
	printf("%u", ui);
	(*count)++;
}

void printOctal(unsigned int ui, int *count) {
	printf("%o", ui);
	(*count)++;
}

void printHexadecimal(unsigned int ui, int *count) {
	printf("%x", ui);
	(*count)++;
}

void printAddress(void *addr, int *count) {
	printf("%p", addr);
	(*count)++;
}

int _printf(const char *format, ...) {
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0') {
		if (*format == '%') {
			format++;

			if (*format == 'c') {
				char ch = (char)va_arg(args, int);
				printChar(ch, &count);
			} else if (*format == 's') {
				char *str = va_arg(args, char *);
				printString(str, &count);
			} else if (*format == 'd' || *format == 'i') {
				int num = va_arg(args, int);
				printInteger(num, &count);
			} else if (*format == 'u') {
				unsigned int ui = va_arg(args, unsigned int);
				printUnsignedInt(ui, &count);
			} else if (*format == 'o') {
				unsigned int ui = va_arg(args, unsigned int);
				printOctal(ui, &count);
			} else if (*format == 'x' || *format == 'X') {
				unsigned int ui = va_arg(args, unsigned int);
				printHexadecimal(ui, &count);
			} else if (*format == 'p') {
				void *addr = va_arg(args, void *);
				printAddress(addr, &count);
			} else if (*format == '%') {
				printChar('%', &count);
			} else {
				printString("Unknown:[%%%c]", &count);
				count += 12;
			}
		} else {
			printChar(*format, &count);
		}

		format++;
	}

	va_end(args);
	return count;
}
