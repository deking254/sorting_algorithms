#include "sort.h"
#include <stdio.h>
void print_pointer(listint_t *new, int size);
int pointer_size(listint_t *new);
listint_t *to_head(listint_t *new);
listint_t *switcher(listint_t *new, int pos);
/**
 * insertion_sort_list - Entry point
 * @list: List
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
int i = 0;
listint_t *new = *list;
listint_t *altered = NULL;
while (new)
{
if (new->next)
{
if (new->next->n < new->n)
{
new = to_head(new);
altered = switcher(new, i);
print_pointer(altered, pointer_size(altered));
if (i != 0)
i = 0;
else
i++;
}
else
{
new = new->next;
i++;
}
}
else
break;
}
*list = to_head(new);
}
/**
 * pointer_size - Entry point
 * @new: the list
 * Return: Always int
 */
int pointer_size(listint_t *new)
{
int size = 0;
while (new)
{
new = new->next;
size += 1;
}
return (size);
}
/**
 * print_pointer - Entry point
 * @new: the list
 * @size: length of the list
 * Return: Always nothing
 */
void print_pointer(listint_t *new, int size)
{
int i = 0;
while (new)
{
printf("%d", new->n);
new = new->next;
i++;
if (i != size)
printf(", ");
else
printf("\n");
}
}
/**
 * to_head - Entry point
 * @new: the list
 * Return: Always nothing
 */
listint_t *to_head(listint_t *new)
{
listint_t *ne = new;
while (ne)
{
if (ne->prev)
ne = ne->prev;
else
break;
}
return (ne);
}
/**
 * switcher - Entry point
 * @new: the list
 * Return: Always nothing
 */
listint_t *switcher(listint_t *new, int pos)
{
int i = 0;
listint_t *first = NULL, *second = NULL;
listint_t *higher_outlier = NULL, *lower_outlier = NULL;
while (new)
{
if (i == pos)
{
first = new;
break;
}
new = new->next;
i++;
}
if (first)
{
second = first->next;
if (second)
higher_outlier = second->next;
}
lower_outlier = first->prev;
if (lower_outlier)
lower_outlier->next = second;
if (second)
second->prev = lower_outlier;
if (higher_outlier)
higher_outlier->prev = first;
first->next = higher_outlier;
first->prev = second;
if (second)
second->next = first;
new = to_head(second);
return (new);
}
