#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "mergesort.h"
#include "array_merge.h"

int* removeDups(int size, int values[])
{
	int duplicates = 0;
	//Loop through every element in the array (excluding the last) and check the position one to the right of it. If they match, 'delete' it
	for(int i = 0; i < size - 1; i++)
	{
		//If the value to the right is the same, 'delete it'
		if(values[i] == values[i + 1])
		{
			//Shift to the left by one
			for(int o = i; o < size; o++)
			{
				values[o] = values[o + 1];
			}
			duplicates++;
		}
	}

	//Create a new array of appropriate size to store list trimmed of duplicates
	int new_size = size - duplicates;
	
	//Allocate memory for it
	int* new_values = (int*) calloc(new_size + 1, sizeof(int));

	//Copy everything from values to new values (since it is now properly trimmed)
	for(int i = 0; i < new_size; i++)
	{
		new_values[i] = values[i];
	}

	return new_values;
}

int* array_merge(int num_arrays, int* sizes, int** values)
{
	//Calculate the size of the resulting array that we will dump by counting all the elements in each array and adding them up
	int size = 0;
	for(int i = 0; i < num_arrays; i++)
	{
		size += sizes[i];
	}

	//Create a new array to hold every value from every array
	int* destination = (int*) calloc(size + 1, sizeof(int));

	//Begin adding every value from every array into a single array 
	int desIndex = 0;
	for(int i = 0; i < num_arrays; i++)
	{
		for(int j = 0; j < sizes; j++)
		{
			destination[desIndex] = values[i][j];
		}	
	}

	//Sort the resulting array using previously created method of mergesort
	destination = mergesort(size, destination);

	//Remove any duplicates
	values = removeDups(size, destination);

	//No longer need destination
	free(destination);
}
