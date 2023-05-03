#include "lists.h"

/**
 * listint_count - counts the number of nodes in a linked list of integers
 * @head: pointer to the first node in the list
 *
 * Return: the number of nodes in the list
 */
size_t listint_count(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return (count);
}

