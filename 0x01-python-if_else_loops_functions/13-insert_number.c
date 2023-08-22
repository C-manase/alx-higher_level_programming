#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: A pointer the head of the linked list.
 * @number: The number to insert.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *new;

	new = malloc(sizeof(listint_t));
	if (new != NULL)
	{
		new->n = number;
		if (*head == NULL || (*head)->n >= new->n)
		{
			new->next = *head;
			*head = new;
			return (new);
		}
		else
		{
			node = *head;
			while (node->next != NULL && node->next->n < new->n)
				node = node->next;
			new->next = node->next;
			node->next = new;
			return (new);
		}
	}
	return (NULL);
}
