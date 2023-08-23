#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
void printChar(char ch, int *count);
void printString(const char *str, int *count);
void printInteger(int num, int *count);
void printUnsignedInt(unsigned int ui, int *count);
void printOctal(unsigned int ui, int *count);
void printHexadecimal(unsigned int ui, int *count);
void printAddress(void *addr, int *count);

#endif
