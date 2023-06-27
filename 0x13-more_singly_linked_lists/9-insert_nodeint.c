#include "lists.h"

/**
 * insert_nodeint_at_index - adds a new node to a linked list
 * @head: pointer to the head of the list
 * @idx: index of the list where the new node will be added
 * @n: value for the new node to be added
 * Return: pointer to the new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode, *temp = *head;
	unsigned int i;

	newNode = malloc(sizeof(listint_t));

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;

	if (idx == 0)
	{
		newNode->next = temp;
		*head = newNode;
		return (newNode);
	}
	else
	{
		for (i = 0; i < (idx - 1) && temp != NULL; i++)
		{
			if (temp == NULL)
				return (NULL);

			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}
	return (newNode);
}
