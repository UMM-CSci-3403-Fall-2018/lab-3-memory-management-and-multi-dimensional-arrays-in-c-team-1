#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"
#include "array_merge.h"

//g++ -Wall -g -o array_merge_test array_merge_test.cpp array_merge.c -lgtest
//valgrind --leak-check=full ./array_merge_test

void removeDuplicates(int array_size, int* array)
{
	if(array_size > 1)
	{
		array_index = 0;

		int *temp_array = (int*) calloc(array_size, sizeof(int));

		for(int i = 0; i < array_size - 1; i++)
		{
			if(array[i] != array[i + 1])
			{
				temp_array[array_index] = array[i];
				array_index++;
			}
		}

		temp_array[array_index] = array[array_size - 1];
		array_index++;
	}
}

int* array_merge(int num_arrays, int* sizes, int** values)
{
	//Variable initialization
	int new_array_size = 0;
	int new_array_index = 0;

	//Calculate the size of the resulting array that we will dump by counting all the elements in each array and adding them up
	for(int i = 0; i < num_arrays; i++)
	{
		new_array_index += sizes[i];
	}

	//Create a new array to hold every value from every array.
	int *new_array = (int*) calloc(new_array_size + 1, sizeof(int));

	//Add all values from values[i][o] into one array.
	for(int i = 0; i < num_arrays; i++)
	{
		for(int o = 0; o < sizes[i]; o++)
		{
			new_array[new_array_index] = values[i][o];
			new_array_index++;
		}
	
	}

	//Sort the array
	mergesort(new_array_size, new_array);

	for(int i = 0; i < new_array_size; i++)
	{
		printf("%d ", new_array[i]);
	}

	//Return null for now
	return new_array;
}
