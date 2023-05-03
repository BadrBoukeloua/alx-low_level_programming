#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely to avoid
 * infinite loops caused by circular references.
 * @head: Pointer to the head of the linked list to be freed.
 *
 * Return: The number of nodes that were freed.
 */
size_t free_listint_safe(listint_t **head)
{
	size_t node_count = 0;
	int diff;
	listint_t *current;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		diff = *head - (*head)->next;
		if (diff > 0)
		{
			current = (*head)->next;
			free(*head);
			*head = current;
			node_count++;
		}
		else
		{
			free(*head);
			*head = NULL;
			node_count++;
			break;
		}
	}

	*head = NULL;

	return (node_count);
}

