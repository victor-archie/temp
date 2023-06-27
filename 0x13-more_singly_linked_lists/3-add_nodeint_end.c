#include "lists.h"
/**
  * add_nodeint_end - add node at end of a listint_t list.
  *
  * @head: head of double pointer
  * @n: int add the list
  * Return: NULL if it failed
  */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end_node, *temp;

	end_node = malloc(sizeof(listint_t));
	if (end_node == NULL)
	{
		return (NULL);
	}

	end_node->n = n;
	end_node->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = end_node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = end_node;
	}

	return (end_node);
}
