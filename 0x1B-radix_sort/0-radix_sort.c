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
	int bucket[10][10], bucket_cnt[10];
	size_t i;
	int j, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(array, size);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_cnt[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		for (i = 0; i < size; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}
