/* handle_char.c */

#include "main.h"

/**
 * handle_char - Handles the '%c' format specifier.
 * @args: Variable argument list.
 * @printed_chars: Pointer to the count of printed characters.
 *
 * Return: Always 1 (number of characters printed).
 */
int handle_char(va_list args, int *printed_chars)
{
	char arg = (char)va_arg(args, int);

	write(1, &c, 1);
	(*printed_chars)++;
	return (1);
}
