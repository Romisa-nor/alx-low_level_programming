/*
 * task number 4 add_nodeint_end
 * by : Romi 
 */
#include "lists.h"
/**
 * add_nodeint_end - adds a node to the bottom . 
 * @head: pointer to first node .
 * @h: value for new node .
 *
 * Return: pointer to new node .
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}
