/*
 * File: 4-free_list.c
 * By Romi
 */

#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list from memory .
 * @head: A pointer to the list_t list.
 */
void free_list(list_t *head)
{
	list_t *tmps;

	while (head)
	{
		tmps = head->next;
		free(head->str);
		free(head);
		head = tmps;
	}
}
