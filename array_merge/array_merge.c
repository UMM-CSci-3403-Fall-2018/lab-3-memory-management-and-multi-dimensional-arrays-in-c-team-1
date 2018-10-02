#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"
#include "array_merge.h"

//g++ -Wall -g -o array_merge_test array_merge_test.cpp array_merge.c -lgtest
//valgrind --leak-check=full ./array_merge_test

void removeDups(int size, int* values, int* sizes)
{
	//Size
	if(size > 2)
	{
		int duplicates = 0;
			//Loop through every element in the array and check the position one to the right of it. If they match, 'delete' it
			for(int i = 0; i < size - 1; i++)
			{
				if(values[i] == values[i + 1])
				{
					for(int o = i; o < size - 1; o++)
					{
						values[o] = values[o + 1];
					}
					duplicates++;
				}
			}

			int* new_values = (int*) calloc(size - duplicates, sizeof(int));

			new_values[0] = size - duplicates;
			new_values[size - duplicates - 1] = '\0';

			for(int i = 1; i < size - duplicates - 1; i++)
			{
				new_values[i] = values[i];
			}
	
			sizes = new_values;
	}
	else
	{
		sizes[0] = 0;
		sizes[1] = '\0';
	}
}

int* array_merge(int num_arrays, int* sizes, int** values)
{
	
	//Calculate the size of the resulting array that we will dump by counting all the elements in each array and adding them up
	//Size starts at 1 due to adding an additional element at [0] to keep track of the number of elements
	int size = 1;
	for(int i = 0; i < num_arrays; i++)
	{
		size += sizes[i];
	}

	//Create a new array to hold every value from every array. 1 is added for null pointer.
	int* destination = (int*) calloc(size + 1, sizeof(int));

	//Add all values from values[i][o] into one array.
	int destIndex = 0;
	for(int i = 0; i < num_arrays; i++)
	{
		for(int o = 0; o < sizes[i]; o++)
		{
			destination[destIndex] = values[i][o];
			destIndex++;
		}
	
	}

	//Sort list
	mergesort(size + 1, destination);

	printf("%d ", size);

	//Remove duplicates
	removeDups(size + 1, destination, sizes);

	for(int i = 0; i < size + 1; i++)
	{
		printf("%d ", sizes[i]);
	}

	//Free
	free(destination);

	//Return null for now
	return sizes;
}
