#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the data in a linked list
 * @head: Pointer to the first element of the list
 *
 * Return: Sum of all data in the linked list
 */
int sum_listint(listint_t *head)
{
	int total_sum = 0;
	listint_t *temp_node = head;

	while (temp_node)
	{
		total_sum += temp_node->n;
		temp_node = temp_node->next;
	}

	return (total_sum);
}

