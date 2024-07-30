/* handle_string.c */

#include "main.h"

/**
 * handle_string - Handles the '%s' format specifier.
 * @args: Variable argument list.
 * @printed_chars: Pointer to the count of printed characters.
 *
 * Return: Number of characters printed.
 */
int handle_string(va_list args, int *printed_chars)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
		len++;

	write(1, str, len);
	(*printed_chars) += len;
	return (len);
}
