/*
 * File: 1-list_len.c
 * By:romi .
 */

#include "lists.h"

/**
 * list_len - Finds the number of elements in
 * a linked list_t list.
 * @l: The linked list_t list.
 *
 * Return: The number of elements in l.
 */
size_t list_len(const list_t *h)
{
	size_t elements = 0;

	while (l)
	{
		elements++;
		l = l->next;
	}

	return (elements);
}
