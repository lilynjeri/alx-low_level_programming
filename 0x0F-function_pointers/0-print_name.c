#include "function_pointers.h"
#include <stdio.h>
/**
* print_name - prints a name using a function pointer
* @name: The name to be printed
* @f: A pointer to a function that takes a char pointer as an argument
*
* Description: This function takes a string `name` and a function pointer `f`.
* It checks if `name` and `f` are not NULL and, if so, it calls the function
* pointed to by `f` and passes `name` to it for printing.
*/
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;


f(name);
}
