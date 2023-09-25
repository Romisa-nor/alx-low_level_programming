#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes
 *
 * @s:first occurrence in the string
 *
 * @accept: matches one of the bytes, or @NULL if no such byte
 *
 * Return: a pointer to the byte
 */
char *_strpbrk(char *s, char *accept)
{
	int i, itr;
	char *p;

	int = 0;
	while (*s[itr] != '\0')
	{
		i = 0;
		while (accept[i] != '\0')
		{
			if (s[itr] == accept[i])
			{
				p = &s[itr];
				return (p);
		}
		i++;
	}
	itr++;
	
}
return (0);
