#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct format_specifier - Struct to define a format specifier
 * @specifier: The format specifier (e.g., "c", "s", "d", etc.)
 * @handler: A function pointer to the corresponding handler function
 */
typedef struct format_conv
{
	char *specifier;
	int (*handler)(va_list);
} format_specifier;

int handler(const char *format, format_specifier fmt[], va_list arg_list);

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_perc(va_list args);
int print_int(va_list args);
int print_bin(va_list args);
int print_uns_int(va_list args);
int print_oct(va_list args);
int print_hex_low(va_list args);
int print_hex_up(va_list args);
int print_add_p(va_list args);
int print_rev(va_list args);

int _putchar(char c);

#endif /* MAIN_H */
