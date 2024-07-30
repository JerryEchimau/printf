/* _printf.c */

#include "main.h"

/* Static Jump Table */
static format_handler handlers[] = {
	handle_char,
	handle_string,
	handle_percent
};

/**
 * handle_specifier - checks specifier and maps to the right handler
 * @format: format character
 * @args: arguments
 * @printed_chars: printed characters
 *
 * Return: printed chars
 */
static int handle_specifier(const char format, va_list args, int *printed_chars)
{
	int i = 0;

	while (i < 3 && format != '\0') /* Mapping handlers */
	{
		if ((format == 'c' && i == 0) ||
				(format == 's' && i == 1) ||
				(format == '%' && i == 2))
		{
			return (handlers[i](args, printed_chars));
		}
		i++;
	}
	return (0); /* Not a valid specifier */
}


/**
 * _printf - Custom ``printf`` function
 * @format: Format string
 *
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1); /* handle NULL format string */

	while (*format)
	{
		if (*format == '%') /* a specifier? */
		{
			format++; /* move to next */

			if (format) /* check for specifier */
				printed_chars += handle_specifier(*format, args, &printed_chars);
		}
		else /* print it as it is */
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++; /* next character */
	}
	va_end(args);
	return (printed_chars);
}
