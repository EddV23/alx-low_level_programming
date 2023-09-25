#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given position
 * @head: A pointer to a pointer to the head of the listint_t list
 * @index: The index of the node to delete. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;
	while (current != NULL)
	{
		if (count == index - 1)
		{
			if (current->next == NULL)
				return (-1);

			temp = current->next;
			current->next = temp->next;
			free(temp);
			return (1);
		}
		count++;
		current = current->next;
	}

	return (-1);
}
