#include "lists.h"

listint_t *add_nodeint(listint_t **head, const int n);

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to a pointer to the head of the listint_t list
 * @idx: The index where the new node should be added. Index starts at 0
 * @n: The value to set in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 *         If it is not possible to add the new node at index idx,
 *         do not add it and return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	temp = *head;
	while (temp != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(listint_t));
			if (new_node == NULL)
				return (NULL);

			new_node->n = n;
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}

		temp = temp->next;
		count++;
	}

	return (NULL);
}

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: A pointer to a pointer to the head of the listint_t list
 * @n: The value to set in the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
