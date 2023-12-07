/*
 * first task 0-print_listint.c
 * by Romi
 */
#include "lists.h"
/**
 * prints all the elements of a listint_t list .
 * @h : pointer to first node . 
 *
 * Return : size of list .
 */
size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n",h->n);
		h = h->next;
		i++;
	}
	return (i);
}
