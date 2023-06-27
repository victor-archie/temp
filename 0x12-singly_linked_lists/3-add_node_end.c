#include "lists.h"

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *endNode, *temp;
	int n = 0;

	endNode = malloc(sizeof(list_t));
	if (endNode == NULL)
	{
		return (NULL);
	}

	endNode->str = strdup(str);

	while (str[n])
	{
		n++;
	}

	endNode->len = n;
	endNode->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = endNode;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = endNode;
	}

	return (*head);
}
