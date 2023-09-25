#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: A pointer to the head of the listint_t list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t node_count = 0;
	const listint_t *visited[1024];

	while (current != NULL)
	{
		size_t i;

		for (i = 0; i < node_count; i++)
		{
			if (current == visited[i])
			{
				printf("[%p] %d\n", (void *)current, current->n);
				return (node_count);
			}
		}

		visited[node_count++] = current;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
	}

	return (node_count);
}
