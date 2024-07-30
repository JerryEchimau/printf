/* handle_percent.c */

#include "main.h"

/**
 * handle_percent - Handles the '%%' format specifier (literal '%').
 * @args: Variable argument list (not used in this handler).
 * @printed_chars: Pointer to the count of printed characters.
 *
 * Return: Always 1 (number of characters printed).
 */
int handle_percent(va_list args, int *printed_chars)
{
	(void)args; /* Suppress unused parameter warning */

	write(1, "%", 1);
	(*printed_chars)++;
	return (1);
}
