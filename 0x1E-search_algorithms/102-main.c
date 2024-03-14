#include "search_algos.h"

/* Function prototype for interpolation_search */
int interpolation_search(int *array, size_t size, int value);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = { /* your array values here */ };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 3, interpolation_search(array, size, 3));
    /* additional code for testing other scenarios */

    return (EXIT_SUCCESS);
}
