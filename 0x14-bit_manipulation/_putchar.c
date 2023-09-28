#include "main.h"
#include <unistd.h>
/**
 * _putchar - Write a char c to standard output
 * @c: The char to print
 *
 * Return: On Success 1
 * On error, -1 will be returned, and errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
