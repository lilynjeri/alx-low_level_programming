#include "variadic_functions.h"

/**
* print_char - Print a character.
* @a_list: The va_list that contains the argument.
*/
void print_char(va_list a_list)
{
printf("%c", va_arg(a_list, int));
}

/**
* print_int - Print an integer.
* @a_list: The va_list that contains the argument.
*/
void print_int(va_list a_list)
{
printf("%i", va_arg(a_list, int));
}

/**
* print_float - Print a float.
* @a_list: The va_list that contains the argument.
*/
void print_float(va_list a_list)
{
printf("%f", va_arg(a_list, double));
}

/**
* print_string - Print a string.
* @a_list: The va_list that contains the argument.
*/
void print_string(va_list a_list)
{
char *str = va_arg(a_list, char*);

if (str == NULL)
str = "(nil)";

printf("%s", str);
}

/**
* print_all - Prints all of the arguments when specified.
* @format: specifies the necessary operations.
*/
void print_all(const char * const format, ...)
{
int i;
int flag;
va_list a_list;

va_start(a_list, format);

i = 0;
while (format != NULL && format[i] != '\0')
{
switch (format[i])
{
case 'c':
print_char(a_list);
flag = 0;
break;

case 'i':
print_int(a_list);
flag = 0;
break;

case 'f':
print_float(a_list);
flag = 0;
break;

case 's':
print_string(a_list);
flag = 0;
break;

default:
flag = 1;
break;
}

if (format[i + 1] != '\0' && flag == 0)
printf(", ");

i++;
}

printf("\n");

va_end(a_list);
}
