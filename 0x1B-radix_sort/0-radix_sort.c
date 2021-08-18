#include "sort.h"

/**
 *
 *
 *
 *
 *
 */
int get_max (int a[], int n){
   int max = a[0];
   for (int i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
}

/**
 *
 *
 *
 *
 *
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_cnt[10];
	size_t i;
	int j, k, r, NOP = 0, divisor = 1, lar, pass;
	lar = get_max (array, size);
	while (lar > 0){
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < 10; i++){
			bucket_cnt[i] = 0;
		}
		for (i = 0; i < size; i++){
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_cnt[r]] = array[i];
			bucket_cnt[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++){
			for (j = 0; j < bucket_cnt[k]; j++){
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		for (i = 0; i < size; i++)
			printf ("%d ", array[i]);
		printf ("\n");
	}
}
