<<<<<<< HEAD
#include "main.h"

/**
 * main - Print _putchar
 * Return: Always 0
 */
int main(void)
{
	_putchar('_');
	_putchar('p');
	_putchar('u');
	_putchar('t');
	_putchar('c');
	_putchar('h');
	_putchar('a');
	_putchar('r');
	_putchar('\n');
	return (0);
}
=======
#include <main.h>

/**
 * main - Print _putchar
 * Return: Always 0
 */

int main(void)
{
  char c = '_';
  write(1, &c, 1);
  c = 'p';
  write(1, &c, 1);
  c = 'u';
  write(1, &c, 1);
  c = 't';
  write(1, &c, 1);
  c = 'c';
  write(1, &c, 1);
  c = 'h';
  write(1, &c, 1);
  c = 'a';
  write(1, &c, 1);
  c = 'r';
  write(1, &c, 1);
  c = '\n';
  write(1, &c, 1);

  return (0);
}
>>>>>>> 8c21b72b0187eddcdef2f21dd7d5602b6ca9c4bd
