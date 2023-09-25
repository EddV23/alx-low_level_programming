#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: A pointer to a pointer to the head of the listint_t list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *next_node;

	next_node = *h;
	while (next_node != NULL)
	{
		next_node = *h;
		*h = next_node->next;
		free_listint(next_node);
		size++;
	}

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
	if (head == NULL)
		return;

	free_listint(head->next);
	free(head);
}
