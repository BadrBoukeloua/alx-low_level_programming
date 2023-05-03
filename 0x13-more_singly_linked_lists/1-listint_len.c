#include "lists.h"

/**
 * listint_count - counts the number of nodes in a linked list of integers
 * @head: pointer to the first node in the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
size_t count = 0;

for (; h != NULL; h = h->next)
{
printf("%d\n", h->next)
	count ++;	;
}
return(count);
}
