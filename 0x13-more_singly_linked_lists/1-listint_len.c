/*
 * task 1-listint_len.c
 * by Romi 
 */
#include "lists.h"

/**
 * size_t listint_len - print a linked listint_t list
 * @h: pointer to the first node.
 *
 * Return: size of list.
 */
size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
