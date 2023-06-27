#include "lists.h"

/**
 * list_len - prints the length of a list
 * @h: linked list
 * Return: returns the number of elements in the linked list
 */

size_t list_len(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
