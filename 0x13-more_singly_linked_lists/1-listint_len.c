#include "lists.h"

/**
 * listint_len - Returns the number of nodes in a linked list
 * @head: Pointer to the first element of the list
 *
 * Return: Number of nodes in the linked list
 */
size_t listint_len(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return (count);
}

