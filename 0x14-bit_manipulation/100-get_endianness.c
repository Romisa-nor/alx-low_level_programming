#include "main.h"

/**
 * get_endianness - Checks the endianness.
 *
 * Return: If big-endian - 0.
 *         If little-endian - 1.
 * By : Romi .
 */
int get_endianness(void)
{
	int num = 1;
	char *end = (char *)&num;

	if (*end == 1)
		return (1);

	return (0);
}
