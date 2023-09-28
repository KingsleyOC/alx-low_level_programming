#include "main.h"

/**
 * set_bit - will set a bit at given index to 1
 * @n: pointer to the num for change
 * @index: index of bit to set to 1
 *
 * Return: 1 success, -1 failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
		if (index > 63)
			return (-1);

		*n = ((1UL << index) | *n);
		return (1);
}
