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
  listint_t *new_node = malloc(sizeof(listint_t));
  if (!head || !new_node)
    return (0);
  new_node->next = 0 ;
  new_node->n = n;
  if (*head)
      new_node->next = *head;
  else
{
  node = *head;
  while (node->next)
       node = node->next;
node->next = new_node;
}
return (new_node);
}
 
