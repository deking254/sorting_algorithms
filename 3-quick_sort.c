#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
size_t smallest(int *arr, size_t starting_index, size_t size);
void print_arr(int *arr, size_t size);
size_t largest(int *arr, size_t starting_index);
/**
 * main - Entry point
 *
 * Return: Always 0
 */
void quick_sort(int *array, size_t size)
{
int current, second, smallist;
size_t index, smallst;
size_t i = 0, j = 2;
while(i < size)
{
current = array[i];
index = largest(array, size - 1);
smallst = smallest(array, i, size);
second = array[smallst];
if (index != size - 1)
{
array[i] = second;
array[smallst] = current;
if (smallst != i)
print_arr(array, size);
}
else
{
index = largest(array, size - j);
current = array[index];
smallist = array[index + 1];
if (current > smallist)
{
array[index + 1] = current;
array[index] = smallist;
print_arr(array, size);
}
else
j++;
}
i++;
}
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
size_t largest(int *arr, size_t starting_index)
{
int status = 0;
size_t i = 0; 
while (i < starting_index)
{
if (arr[starting_index] < arr[i])
{
status = 1;
starting_index -= 1;
}
i++;
if (status == 1)
i = 0;
status = 0;
}
if (status == 0)
return (starting_index);
else
return (0);
}
