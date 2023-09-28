#include "main.h"

/**
 * get_bit - Will return value of a bit at an index in a dec num
 * @n: The num to search
 * @index: The index of bit
 *
 * Return: The value of bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_king;

	if (index > 63)
		return (-1);
	bit_king = (n >> index) & 1;

	return (bit_king);
}
