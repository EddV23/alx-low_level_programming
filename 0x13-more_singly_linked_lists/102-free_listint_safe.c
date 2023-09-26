#include "lists.h"

void free_listint(listint_t *head);

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: A pointer to a pointer to the head of the listint_t list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *next_node;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (next_node != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		size++;
	}

	*h = NULL;
	return (size);
}

/**
 * free_listint - Frees a listint_t list
 * @head: a pointer to the head of the listint_t list
 *
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *next_node;

	while (head != NULL)
	{
		next_node = head;
		next_node = next_node->next;
		free(next_node);
	}
}
