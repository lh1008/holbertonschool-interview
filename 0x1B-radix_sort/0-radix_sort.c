#include "sort.h"

/**
 * get_max - entry to get max
 * Desc: get_max function gets maximum number
 * @array: int array of numbers to sort
 * @size: size_t size of array
 * Return: return array
 */
int get_max(int array[], size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * csort_radix - counting sort to be called by radix_sort
 * @array: array to sort
 * @size: size of array
 * @sig_dig: current significant digit to sort
 * @sorted: array to store sorted values in
 */
void csort_radix(int *array, size_t size, int sig_dig, int *sorted)
{
	int count[BASE] = {0};
	size_t i;
	ssize_t j;

	for (i = 0; i < size; ++i)
		++count[array[i] / sig_dig % 10];
	for (i = 1; i < BASE; ++i)
		count[i] += count[i - 1];
	for (j = size - 1; j >= 0; --j)
	{
		sorted[count[array[j] / sig_dig % 10] - 1] = array[j];
		--count[array[j] / sig_dig % 10];
	}
	memcpy(array, sorted, size * sizeof(*sorted));
}

/**
 * radix_sort - entry to radiz sort
 * Desc: radix_sort function that sorts an array of integers
 * in ascending order using Radix sort algorithm
 * (LSD - least significant digit)
 * @array: int arrat numbers to sort
 * @size: size_t size of array
 * Return: nothing, void function
 */
void radix_sort(int *array, size_t size)
{
	int max, sig_dig, *sorted;

	if (!array || size < 2)
		return;
	sorted = calloc(size, sizeof(*sorted));
	if (!sorted)
		return;
	max = get_max(array, size);
	for (sig_dig = 1; max / sig_dig > 0; sig_dig *= BASE)
	{
		csort_radix(array, size, sig_dig, sorted);
		print_array(array, size);
	}
	free(sorted);
}
