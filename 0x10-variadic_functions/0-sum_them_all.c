#include "variadic_functions.h"
#include <stdarg.h>

/**
* sum_them_all - Returns the sum of a variable number of parameters.
* @n: The number of parameters passed to the function.
* @...: A variable number of parameters to calculate the sum of.
*
* Description: This function takes the number of parameters `n` and a variable
* number of parameters. It calculates the sum of all the parameters and returns
* the result.
*
* Return: If n == 0, the function returns 0.
*         Otherwise, it returns the sum of all the parameters.
*/
int sum_them_all(const unsigned int n, ...)
{
va_list ap;
unsigned int i, sum = 0;


va_start(ap, n);


for (i = 0; i < n; i++)
sum += va_arg(ap, int);


va_end(ap);


return (sum);
}

