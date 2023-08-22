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
			} else if (*format == 'r') {
				printString("Unknown:[%r]", &count);
				count += 10;
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

int main() {

	printf("Length:[%d, %i]\n", _printf("Length:[%d, %i]\n", 39, 39), _printf("Length:[%d, %i]\n", 39, 39));
	printf("Negative:[%d]\n", _printf("Negative:[%d]\n", -762534));
	printf("Unsigned:[%u]\n", _printf("Unsigned:[%u]\n", 2147484671));
	printf("Unsigned octal:[%o]\n", _printf("Unsigned octal:[%o]\n", 20000001777));
	printf("Unsigned hexadecimal:[%x, %X]\n", _printf("Unsigned hexadecimal:[%x, %X]\n", 2147484671, 2147484671));
	printf("Character:[%c]\n", _printf("Character:[%c]\n", 'H'));
	printf("String:[%s]\n", _printf("String:[%s]\n", "I am a string !"));
	printf("Address:[%p]\n", _printf("Address:[%p]\n", (void *)0x7ffe637541f0));
	printf("Percent:[%%]\n", _printf("Percent:[%%]\n"));
	printf("Len:[%d]\n", _printf("Len:[%d]\n", 12));
	printf("Unknown:[%r]\n", _printf("Unknown:[%r]\n"));

	return 0;
}
