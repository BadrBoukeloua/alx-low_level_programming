#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head node of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
size_t count = 0;

for (; h != NULL; h = h->next)
{
printf("%d\n", h->n);
count = count + 1;
}
return(count);
}
