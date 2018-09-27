#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
//#include <string.h>

#include "mergesort.h"

void mergesort(int size, int values[])
{
	mergesortRange(values, 0, size);
}

bool needsSorting(int rangeSize)
{
	return rangeSize >= 2;
}

void mergesortRange(int [] values, int startIndex, int endIndex)
{
	int rangeSize = endIndex - startIndex;
	if(needsSorting(rangeSize))
	{
		//Odd total array size could cause problems when using this as an int (9 / 2 = 4.5 =/= int)
		int midPoint = (startIndex + endIndex) / 2;
		mergesortRange(values, startIndex, midPoint);
		mergesortRange(values, midPoint, endIndex);
		mergeRanges(values, startIndex, midPoint, endIndex);
	}

	for(int i = 0; i < rangeSize; i++)
	{
		printf("%d ", values[i]);
	}
}

void mergeRanges(int[] values, int startIndex, int midPoint, int endIndex)
{
	const int = rangeSize = endIndex - startIndex;
	//int[] destination = new int[rangeSize];
	int *destination = (int*) calloc(rangeSize, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;

	while(firstIndex < midPoint && secondIndex < endPoint)
	{
		if(values[firstIndex] < values[secondIndex]
		{
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

	while(firstIndex < midPoint)
	{
		destination[copyPoint] = values[firstIndex];
		copyIndex++;
		firstIndex++;
	}

	while (secondIndex < endIndex)
	{
		destination[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}

	for(int i = 0; i < rangeSize; i++)
	{
		values[i + startIndex] = destination[i];
	}

	free(destination);
}
