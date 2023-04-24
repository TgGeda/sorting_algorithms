#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left = *list, *right = NULL, *current = NULL;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        while (left->next != right)
        {
            if (left->n > left->next->n)
            {
                current = left->next;
                if (left->prev != NULL)
                    left->prev->next = current;
                else
                    *list = current;
                current->prev = left->prev;
                left->prev = current;
                left->next = current->next;
                if (current->next != NULL)
                    current->next->prev = left;
                current->next = left;
                left = current;
                swapped = 1;
                print_list(*list);
            }
            else
                left = left->next;
        }
        right = left;
        while (right->prev != NULL)
        {
            if (right->n < right->prev->n)
            {
                current = right->prev;
                if (right->next != NULL)
                    right->next->prev = current;
                current->next = right->next;
                right->prev = current->prev;
                if (current->prev != NULL)
                    current->prev->next = right;
                else
                    *list = right;
                right->next = current;
                current->prev = right;
                right = current;
                swapped = 1;
                print_list(*list);
            }
            else
                right = right->prev;
        }
        left = right;
    }
}
