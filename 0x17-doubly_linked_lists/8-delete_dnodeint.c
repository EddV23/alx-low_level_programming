#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at the given index
 *                            of a dlistint_t list
 * @head: pointer to a pointer that points to the head of the linked list
 * @index: index of the node to be deleted
 *
 * Return: 1 if the deletion was successful, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	if (current->next == NULL)
	{
		current->prev->next = NULL;
		free(current);
		return (1);
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	free(current);

	return (1);
}
