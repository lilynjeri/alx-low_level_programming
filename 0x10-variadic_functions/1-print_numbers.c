#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>


/**
* print_numbers - Prints numbers, followed by a new line.
* @separator: The string to be printed between numbers.
* @n: The number of integers passed to the function.
* @...: A variable number of numbers to be printed.
*
* Description: This function takes a string `separator`, the number of
* integers `n`, and a variable number of integers. It prints the integers
* separated by the `separator` string and followed by a newline character.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list nums;
unsigned int index;


va_start(nums, n);


for (index = 0; index < n; index++)
{
printf("%d", va_arg(nums, int));


if (index != (n - 1) && separator != NULL)
printf("%s", separator);
}


printf("\n");


va_end(nums);
}
