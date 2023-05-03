#include "lists.h"

/**
 * count_listint_nodes - counts the number of nodes in a linked list
 * @head: pointer to the head node of the linked list
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}

