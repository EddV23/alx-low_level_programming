#include "variadic_functions.h"

/**
 * print_all - prints arguments based on format
 * @format: a list of types of arguments to be printed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *sep = "";
	unsigned int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(args, int));
			break;
		case 'i':
			printf("%s%d", sep, va_arg(args, int));
			break;
		case 'f':
			printf("%s%f", sep, va_arg(args, double));
			break;
		case 's':
		{
			char *str = va_arg(args, char *);

			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str);
			break;
		}
		default:
			i++;
			continue;
		}
		sep = ", ";
		i++;
	}

	va_end(args);
	printf("\n");
}
