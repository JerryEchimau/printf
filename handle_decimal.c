/* handle_decimal.c */

#include "main.h"

/**
 * handle_decimal - handles the '%c' and '%i' format specifiers
 * @args: variable argument list
 * @printed_chars: pointer to the count of printed chars
 *
 * Return: number of chars printed
 */
int handle_decimal(va_list args, int *printed_chars)
{
	int num = va_arg(args, int);
	char *str;
	int len = 0;
	int is_negative = 0;
	long int temp;

	if (num < 0) /* negative numbers */
	{
		is_negative = 1;
		temp = (long int)num * -1; /* convert to positive for easier handling */
	}
	else
		temp = (long int)num;

	do { /* length of digits */
		len++;
		temp /= 10;
	} while (temp != 0);

	str = malloc(sizeof(char) * (len + 1 + is_negative));
	if (str == NULL)
		return (0);

	str[len + is_negative] = '\0';
	do {
		if (is_negative && len == 0)
			str[0] = '-';
		str[len - 1 + is_negative] = (temp % 10) + '0';
		temp /= 10;
		len--;
	} while (temp != 0);

	write(1, str, (len + 1 + is_negative));
	(*printed_chars) += (len + is_negative);

	free(str);
	return (len + is_negative);
}
