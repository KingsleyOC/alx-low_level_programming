#include <stdio.h>
/**
 *main - Entry point
 *Description: 'print alphabets lowercase and uppercase'
 *Return: always 0
 */
int main(void)
{
	int n = 97; 65;

	while (n <= 122)
	{
		putchar(n);
		n++;
	}
	while (n <= 90)
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
