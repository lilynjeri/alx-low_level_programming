#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
* print_char - Prints a character.
* @list: A va_list of arguments.
*/
void print_char(va_list list)
{
printf("%c", va_arg(list, int));
}

/**
* print_int - Prints an integer.
* @list: A va_list of arguments.
*/
void print_int(va_list list)
{
printf("%d", va_arg(list, int));
}

/**
* print_float - Prints a float.
* @list: A va_list of arguments.
*/
void print_float(va_list list)
{
printf("%f", va_arg(list, double));
}

/**
* print_string - Prints a string.
* @list: A va_list of arguments.
*/
void print_string(va_list list)
{
char *str = va_arg(list, char *);
if (!str)
str = "(nil)";
printf("%s", str);
}

/**
* print_all - Prints anything based on the format provided.
* @format: A list of types of arguments passed to the function.
*
* Description: This function takes a format string and a variable number of
* arguments. It iterates through the format string and prints each argument
* based on its corresponding format specifier. The format string can contain
* 'c' for characters, 'i' for integers, 'f' for floats, and 's' for strings.
* The printed values are separated by commas and followed by a newline.
* If a string argument is NULL, it prints "(nil)".
*/
void print_all(const char * const format, ...)
{
va_list list;
unsigned int i = 0;
char *sep = "";

void (*print_func[])(va_list) = {
print_char,
print_int,
print_float,
print_string
};

va_start(list, format);

if (format)
{
while (format[i] && i < 40)  /* Limiting the number of lines as an example */
{
switch (format[i])
{
case 'c':
case 'i':
case 'f':
case 's':
print_func[format[i] - 'c'](list);
break;
default:
i++;
continue;
}
if (format[i + 1])
printf("%s", sep);
sep = ", ";
i++;
}
}

printf("\n");
va_end(list);
}
