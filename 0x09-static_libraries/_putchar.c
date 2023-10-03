#include "unistd.h"

/**
 * _putchar take char and give int
 *
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
