#include "lists.h"

/**
 * add_node - adds node to beginning of a linked list
 * @head: pointer to the first node
 * @str: string in the node
 * Return: address of the head
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;
	int n = 0;

	newNode = (list_t *)malloc(sizeof(list_t));
	if (newNode == NULL)
	{
		return (NULL);
	}

	newNode->str = strdup(str);

	while (str[n])
	{
		n++;
	}

	newNode->len = n;
	newNode->next = *head;
	*head = newNode;

	return (*head);
}
