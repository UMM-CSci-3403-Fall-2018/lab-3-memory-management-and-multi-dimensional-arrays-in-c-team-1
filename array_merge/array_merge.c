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
	//Check if array is empty
	if(array_size > 0)
	{
		//Intialize variables
		int array_index = 1;
		int duplicates = 0;
		int uniques = 1;

		//Count uniques
		for (int i = 0; i < array_size - 1; i++)
		{
			if(array[i] != array[i + 1])
			{
				uniques++;
			}
		}

		//Allocate enough memory for all uniques and a spot for the size of the array
		int *temp_array = (int*) calloc(uniques + 1, sizeof(int));

		//Check for duplicates
		for(int i = 0; i < array_size - 1; i++)

		{
			//If unique, add to temp_array and increase array_index by 1
			if(array[i] != array[i + 1])
			{
				temp_array[array_index] = array[i];
				array_index++;
			} else {
				
				duplicates++;
			}
		}

		//Add last element because the last element is always unique when using a sorted array
		temp_array[array_index] = array[array_size - 1];
		//Free orginal array
		free(array);
		//Add size of the array to the 0th spot
		temp_array[0] = array_size - duplicates;

		//Return new array
		return temp_array;
	}
	
	//Allocate memory for special case where the size of the array is zero
	int* temp_array = (int*) calloc(1, sizeof(int));
	//Add size of the array to the 0th spot
	temp_array[0] = 0;
	//Free orginal array
	free(array);

	//Return new array
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

	//Create a new array to hold every value from every array.
	int *new_array = (int*) calloc(new_array_size, sizeof(int));


	//Add all values from values[i][o] into one array.
	for(int i = 0; i < num_arrays; i++)
	{
		for(int j = 0; j < sizes[i]; j++)
		{
			new_array[new_array_index] = values[i][j];
			new_array_index++;
		}
	
	}

	

	//Sort the array
	mergesort(new_array_size, new_array);

	//Return the outcome of removing duplicates from the given array
	return removeDuplicates(new_array_size, new_array);
}
