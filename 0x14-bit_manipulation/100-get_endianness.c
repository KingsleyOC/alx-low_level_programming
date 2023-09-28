#include "main.h"

/**
 * get_endianness - will check if a machine is little or big endian
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int q = 1;
	char *c = (char *) &q;

	return (*c);
}
