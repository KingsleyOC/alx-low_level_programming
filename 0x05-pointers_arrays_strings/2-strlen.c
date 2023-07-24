#include "main.h"
/**
 * _strien - returns the length of a string
 * @s: string
 * Return: length
 */
int _strien(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
