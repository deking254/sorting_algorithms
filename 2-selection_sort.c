#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
size_t smallest(int *arr, size_t starting_index, size_t size);
void print_arr(int *arr, size_t size);
/**
 * main - Entry point
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
size_t i = 0;
size_t index = 0, smllest = 0;
while (i < size)
{
index = smallest(array, i, size);
if (index != i)
{
smllest = array[i];
array[i] = array[index];
array[index] = smllest;
print_arr(array, size);
}
i++;
}
return;
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
size_t smallest(int *arr, size_t starting_index, size_t size)
{
size_t i = 0, status = 0;
while (i < size)
{
if (i > starting_index)
{
if (arr[starting_index] > arr[i])
status = 1;
}
i++;
if (status == 1)
{
starting_index += 1;
i = 0;
status = 0;
}
}
if (status == 0)
return (starting_index);
else
return (0);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
void print_arr(int *arr, size_t size)
{
size_t i = 0;
while (i < size)
{
printf("%d", arr[i]);
i++;
if (i == size)
printf("\n");
else
printf(", ");
}
}
