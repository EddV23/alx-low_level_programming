#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a
 *                        listint_t linked list
 * @head: A pointer to the head of the listint_t list
 * @index: The index of the node to return, starting at 0
 *
 * Return: The nth node of the listint_t list, or
 *         NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);

		count++;
		head = head->next;
	}

	return (NULL);
}
