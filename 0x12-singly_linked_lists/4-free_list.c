#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list_t list
 * @head: pointer to the list_t list to free
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
