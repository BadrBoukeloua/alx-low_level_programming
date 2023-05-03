#include "lists.h"
#include <stdio.h>

size_t count_unique_nodes(const listint_t *head);
size_t print_listint(const listint_t *head);

/**

count_unique_nodes - Counts the number of unique nodes

in a linked list of type listint_t.

@head: A pointer to the head of the listint_t to check.

Return: If the list is empty - 0.

Otherwise - the number of unique nodes in the list.
*/
size_t count_unique_nodes(const listint_t *head)
{
const listint_t *slow = head, *fast = head;
size_t nodes = 0;

if (head == NULL)
return (0);

while (slow && fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
slow = head;
while (slow != fast)
{
nodes++;
slow = slow->next;
fast = fast->next;
}
     slow = slow->next;
     while (slow != fast)
     {
         nodes++;
         slow = slow->next;
     }

     return (nodes);
 }
}

nodes = 1;
while (head->next && head->next > head)
{
nodes++;
head = head->next;
}

return (nodes);
}

/**

print_listint - Prints a listint_t list.

@head: A pointer to the head of the listint_t list.

Return: The number of nodes in the list.
*/
size_t print_listint(const listint_t *head)
{
size_t nodes, i;

nodes = count_unique_nodes(head);

for (i = 0; i < nodes && head != NULL; i++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

return (nodes);
}
