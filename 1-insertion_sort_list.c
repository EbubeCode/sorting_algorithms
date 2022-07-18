#include "sort.h"

/**
 * remov - removes an elment from a list
 * @e: element
 */
void remov(listint_t *e)
{
	if (e->next)
		e->next->prev = e->prev;
	e->prev->next = e->next;
	e->next = NULL;
	e->prev = NULL;
}

/**
 * insert - inserts an element in a list
 * @e: element
 * @p: prior node
 */
void insert(listint_t *p, listint_t *e)
{
	listint_t *next;

	next = p->next;
	e->prev = p;
	e->next = next;
	p->next = e;
	next->prev = e;
}


/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * using the Insertion sort algorithm
 *
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *e, *c;
	int i;

	if (list == NULL || *list == NULL)
		return;
	e = (*list)->next;
	while (e)
	{
		print_list(*list);
		i = 0;
		c = e->prev;
		while (c && c->n > e->n)
		{
			c = c->prev;
			i++;
		}
		if (i)
		{
			temp = e;
			e = temp->next;
			remov(temp);
			if (c == NULL)
			{
				temp->next = *list;
				(*list)->prev = temp;
				*list = temp;
			}
			else
				insert(c, temp);
			print_list(*list);
		}
		else
			e = e->next;
	}
}
