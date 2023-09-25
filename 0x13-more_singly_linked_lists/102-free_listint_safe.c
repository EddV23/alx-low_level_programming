#include "lists.h"

size_t listint_len(const listint_t *h);

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: A pointer to a pointer to the head of the listint_t list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *tmp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size++;
		if (current->next >= current)
		{
			tmp = current->next;
			current->next = NULL;
			current = tmp;
		}
		else
		{
			tmp = current->next;
			free(current);
			current = tmp;
			break;
		}
	}
	*h = NULL;
	return (size);
}
