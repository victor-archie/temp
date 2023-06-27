#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: double pointer
 * @index: index of node
 *
 * Return: pointer to the index node
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *pre_node, *temp;
	unsigned int i;

	temp = *head;

	if (temp == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	else
	{
		pre_node = *head;

		for (i = 0; i < (index - 1) && pre_node != NULL; i++)
		{
			if (pre_node->next == NULL)
			{
				return (-1);
			}
			pre_node = pre_node->next;
		}
		temp = pre_node->next;
		pre_node->next = temp->next;
		free(temp);
	}
		return (1);
}
