#include "lists.h"
/**
 * print_integer_list - prints all the integers in a linked list
 * @head: pointer to the head of the integer list
 *
 * Return: number of nodes in the list
 */
size_t print_integer_list(const listint_t *h)
{
    size_t count = 0;

    while (h)
    {
        printf("%d\n", h->n);
        count++;
        h = h->next;
    }

    return (count);
}
