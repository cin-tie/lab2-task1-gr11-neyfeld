/* Author: Student */

/* Program to rearrange digits of numbers to form maximum possible numbers */

#include "../include/digit_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

static void print_array(unsigned int arr[], int size)
{
		int i;
		printf("[");
		for (i = 0; i < size; i++)
		{
				if (i > 0)
						printf(", ");
				printf("%u", arr[i]);
		}
		printf("]");
}

static void generate_random_numbers(unsigned int arr[], int size)
{
		int i;
		srand(time(NULL));

		for (i = 0; i < size; i++)
				arr[i] = rand() % 10000;
}

int main(int argc, char *argv[])
{
		unsigned int numbers[MAX_NUMBERS];
		unsigned int results[MAX_NUMBERS];
		int n, i;

		if (argc != 2)
		{
				printf("Usage: %s <number_of_elements>\n", argv[0]);
				return 1;
		}

		n = atoi(argv[1]);

		generate_random_numbers(numbers, n);

		printf("Original array: ");
		print_array(numbers, n);
		printf("\n");

		for (i = 0; i < n; i++)
				results[i] = max_from_digits(numbers[i]);

		printf("Maximum numbers: ");
		print_array(results, n);
		printf("\n");

		return 0;
}