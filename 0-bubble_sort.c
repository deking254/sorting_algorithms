#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - Entry point
 * @array: the array
 * @size: size of array
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
size_t status = 0;
size_t j = 0;
size_t i = 0;
int upper_tmp = 0;
int lower_tmp = 0;
while (i < size)
{
if ((i + 1) < size)
{
if (array[i + 1] < array[i])
{
status = 0;
upper_tmp = array[i];
lower_tmp = array[i + 1];
array[i] = lower_tmp;
array[i + 1] = upper_tmp;
while (j < size)
{
printf("%d", array[j]);
if (j != size - 1)
printf(", ");
j++;
}
printf("\n");
}
else
{
status += 1;
}
}
i++;
if (status == size - 1)
return;
if (i == size)
i = 0;
j = 0;
}
}
