#include "sort.h"
#include <stdio.h>
#include <sys/types.h>
void switcher(int *array, ssize_t i, ssize_t size);
void q_sort(int *array, ssize_t first, ssize_t last, int size);
int partition(int *array, ssize_t first, ssize_t last, size_t size);
/**
 *quick_sort - check code
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
q_sort(array, 0, size - 1, size);
}
/**
 * switcher - Entry point
 * @array: array
 * @i: i
 * @size: size
 * Return: Always 0
 */
void switcher(int *array, ssize_t item1, ssize_t item2)
{
int tmp;
tmp = array[item1];
array[item1] = array[item2];
array[item2] = tmp;
}
/**
 *partition - lomuto
 *@array: array
 *@init: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int partition(int *array, ssize_t init, ssize_t last, size_t size)
{
int piv = array[last];
ssize_t current = init, finder;
for (finder = init; finder < last; finder++)
{
if (array[finder] < piv)
{
if (array[current] != array[finder])
{
switcher(array, current, finder);
print_array(array, size);
}
current++;
}
}
if (array[current] != array[last])
{
switcher(array, current, last);
print_array(array, size);
}
return (current);
}

/**
 *q_sort - check code
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void q_sort(int *array, ssize_t first, ssize_t last, int size)
{
ssize_t pos = 0;
if (first < last)
{
pos = partition(array, first, last, size);
q_sort(array, first, pos - 1, size);
q_sort(array, pos + 1, last, size);
}
}
