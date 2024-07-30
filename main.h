#ifndef MAIN_H
#define MAIN_H

/* libraries */
#include <stdarg.h>
#include <unistd.h>


/* custom types */
typedef int (*format_handler)(va_list args, int *printed_chars); /* function pointer type */


/* main functions */
int _printf(const char *format, ...);

/* specifiers */
int handle_char(va_list args, int *printed_chars);
int handle_string(va_list args, int *printed_chars);
int handle_percent(va_list args, int *printed_chars);


#endif /* MAIN_H */
