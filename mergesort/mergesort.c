#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "mergesort.h"

//Function to determine if list needs sorting. If it is a list of nothing or a list of size 1, then the lists are technically sorted.
bool needsSorting(int rangeSize)
{
	return rangeSize >= 2;
}

//This is the function that sorts the small, broken up arrays and combines them into a final array
void mergeRanges(int values[], int startIndex, int midPoint, int endIndex)
{
	//Define variables
	const int rangeSize = endIndex - startIndex;
	int *destination = (int*) calloc(rangeSize + 1, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;

	//Begin copying the values array to the newly created (and sorted) array
	while(firstIndex < midPoint && secondIndex < endIndex)
	{	
		//Testing values to see which is smaller than the other
		if(values[firstIndex] < values[secondIndex])
		{
			//Then copy into new sorted array at [copyIndex] location
			destination[copyIndex] = values[firstIndex];
			firstIndex++;
		}
		else
		{
			destination[copyIndex] = values[secondIndex];
			secondIndex++;
		}
		copyIndex++;
	}

	//Add in the first half to sorted array
	while(firstIndex < midPoint)
	{
		destination[copyIndex] = values[firstIndex];
		copyIndex++;
		firstIndex++;
	}

	//Add in second half
	while (secondIndex < endIndex)
	{
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}

	//Add null terminator
	destination[rangeSize] = '\0';
	
	//Replace original unsorted list with new sorted list elements
	for(int i = 0; i < rangeSize; i++)
	{
		values[i + startIndex] = destination[i];
	}
	//No longer using our 'temp' array, so free it
	free(destination);
}

//Act as a 'controller' for the sorting. Splits the arrays into as small as possible 'duos' for comparitive sorting.
void mergesortRange(int values[], int startIndex, int endIndex)
{
	int rangeSize = endIndex - startIndex;

	//Determine if list needs sorting (lists of size 0 or 1 are already sorted)
	if(needsSorting(rangeSize))
	{
		//Find mid point
		int midPoint = (startIndex + endIndex) / 2;

		//Begins breaking up first half into duos, and then in the next line the other half
		mergesortRange(values, startIndex, midPoint);
		mergesortRange(values, midPoint, endIndex);

		//Begins a final sort of all the little duos
		mergeRanges(values, startIndex, midPoint, endIndex);
	}
}

//Sorts an array of ints using mergesort technique
void mergesort(int size, int values[])
{	
	//Calls the 'controller' for the sort
	mergesortRange(values, 0, size);
}
