#include "lists.h"
/**
 * print_list - prints number of elements in a linked list
 * @h: value in each node
 * Return: number of node
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
