#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: A pointer to a pointer to the head of the listint_t list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	size_t node_count = 0;
	listint_t *visited[1024];

	while (current != NULL)
	{
		size_t i;

		for (i = 0; i < node_count; i++)
		{
			if (current == visited[i])
			{
				*h = NULL;
				return (node_count);
			}
		}

		visited[node_count++] = current;
		current = current->next;
		free(*h);
		*h = current;
	}

	*h = NULL;
	return (node_count);
}
