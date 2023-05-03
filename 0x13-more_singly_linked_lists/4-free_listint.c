#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: pointer to the first node in the list to be freed
 *
 * This function frees the memory occupied by each node in a singly linked
 * list of integers. The pointer to the first node is passed as an argument.
 * The function does not return anything.
 */
void free_listint(listint_t *head)
{
	listint_t *current, *next;

	current = head;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
