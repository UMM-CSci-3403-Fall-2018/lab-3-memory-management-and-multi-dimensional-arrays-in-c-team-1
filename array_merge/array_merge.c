#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"
#include "array_merge.h"

//g++ -Wall -g -o array_merge_test array_merge_test.cpp array_merge.c -lgtest
//valgrind --leak-check=full ./array_merge_test

int* removeDuplicates(int array_size, int* array)
{
	if(array_size > 0)
	{
		int array_index = 1;
		int duplicates = 0;
		int uniques = 1;

		for (int i = 0; i < array_size - 1; i++)
		{
			if(array[i] != array[i + 1])
			{
				uniques++;
			}
		}

		printf("%d ", uniques);

		int *temp_array = (int*) calloc(uniques + 1, sizeof(int));

		for(int i = 0; i < array_size - 1; i++)

		{
			if(array[i] != array[i + 1])
			{
				temp_array[array_index] = array[i];
				array_index++;
			} else {
				
				duplicates++;
			}
		}

		
		temp_array[array_index] = array[array_size - 1];
		free(array);
		temp_array[0] = array_size - duplicates;

		printf("%d ", array_size - duplicates);

		for(int i = 0; i < array_size - duplicates; i++)
       	        {
               		 printf("%d ", temp_array[i]);
                }

		return temp_array;
	}
	
	int* temp_array = (int*) calloc(1, sizeof(int));
	temp_array[0] = 0;
	free(array);

	return temp_array;
}

int* array_merge(int num_arrays, int* sizes, int** values)
{
	//Variable initialization
	int new_array_size = 0;
	int new_array_index = 0;

	//Calculate the size of the resulting array that we will dump by counting all the elements in each array and adding them up
	for(int i = 0; i < num_arrays; i++)
	{
		new_array_size = sizes[i] + new_array_size;
	}

	printf("%d ", new_array_size);

	//Create a new array to hold every value from every array.
	int *new_array = (int*) calloc(new_array_size, sizeof(int));


	//Add all values from values[i][o] into one array.
	for(int i = 0; i < num_arrays; i++)
	{
		//printf("%d ", num_arrays);
		for(int j = 0; j < sizes[i]; j++)
		{
			//printf("%d ", sizes[i]);
			new_array[new_array_index] = values[i][j];
			printf("%d ", new_array[new_array_index]);
			new_array_index++;
		}
	
	}

	

	//Sort the array
	mergesort(new_array_size, new_array);

	for(int i = 0; i < new_array_size; i++)
	{
		//printf("%d ", new_array[i]);
	}

	return removeDuplicates(new_array_size, new_array);

	//Return null for now
	//return new_array;
}
