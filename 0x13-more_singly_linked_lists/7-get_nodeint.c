#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: pointer to the first element in the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = head;

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	return (current ? current : NULL);
}

