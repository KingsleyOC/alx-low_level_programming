#include "main.h"

/**
 * flip_bits - Count num of bits to change
 * from one number to another
 * @n: The first num
 * @m: The second num
 *
 * Return: num of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int q, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (q = 63; q >= 0; q--)
	{
		current = exclusive >> q;
		if (current & 1)
			count++;
	}

	return (count);
}
