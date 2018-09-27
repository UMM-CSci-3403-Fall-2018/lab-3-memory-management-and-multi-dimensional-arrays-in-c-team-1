#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "mergesort.h"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values)
{
	int size = 0;
	for(int i = 0; i < num_arrays; i++)
	{
		size = size + sizes[i];
	}
	int* destination = (int*) calloc(size + 1, sizeof(int));
	int desIndex = 0;
	for(int i = 0; i < num_arrays; i++)
	{
		for(int j = 0; j < sizes; j++)
		{
			destination[desIndex] = values[i][j];
		}	
	}
}
